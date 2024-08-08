#include <set>

#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <fcntl.h>
#include <poll.h>

#ifndef POLL_SIZE
#define POLL_SIZE 2048
#endif

int set_non_block(int fd) {
    int flags;

#ifdef O_NONBLOCK
    if (-1 == (flags = fcntl(fd, F_GETFL, 0))) {
        flags = 0;
    }
    return fcntl(fd, F_SETFL, flags | O_NONBLOCK);
#else
    flags = 1;
    return ioctl(fd, FIOBIO, &flags);
#endif
}

int main (int argc, char** argv) {
    int MasterSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    std::set<int> SlaveSockets;

    struct sockaddr_in SockAddr;
    SockAddr.sin_family = AF_INET;
    SockAddr.sin_port = htons(12345);
    SockAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    bind(MasterSocket, reinterpret_cast<sockaddr *>(&SockAddr), sizeof(SockAddr));

    set_non_block(MasterSocket);

    listen(MasterSocket, SOMAXCONN);

    struct pollfd cSet[POLL_SIZE];
    cSet[0].fd = MasterSocket;
    cSet[0].events = POLLIN;

    while (true) {
        unsigned int index = 1;
        for (auto iter = SlaveSockets.begin();
             iter != SlaveSockets.end();
             iter++) {
            cSet[index].fd = *iter;
            cSet[index].events = POLLIN;
            index++;
        }
        unsigned int setSize = 1 + SlaveSockets.size();

        poll(cSet, setSize, -1);

        for (uint32_t i = 0; i < setSize; i++) {
            if (cSet[i].revents & POLLIN) {
                if (i) {
                    static char buffer[1024];
                    int recvSize = recv(cSet[i].fd,
                                        buffer,
                                        1024,
                                        MSG_NOSIGNAL);
                    if ((recvSize == 0) && (errno != EAGAIN)) {
                        shutdown(cSet[i].fd, SHUT_RDWR);
                        close(cSet[i].fd);
                        SlaveSockets.erase(cSet[i].fd);
                    } else if (recvSize > 0) {
                        send(cSet[i].fd,
                             buffer,
                             recvSize,
                             MSG_NOSIGNAL);
                    }
                } else {
                    int SlaveSocket = accept(MasterSocket, 0, 0);
                    set_non_block(SlaveSocket);
                    SlaveSockets.insert(SlaveSocket);
                }
            }
        }
    }

    return 0;
}
