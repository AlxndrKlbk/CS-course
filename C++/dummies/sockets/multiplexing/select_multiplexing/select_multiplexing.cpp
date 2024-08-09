#include <algorithm>
#include <set>

#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <fcntl.h>

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


    while (true) {
        fd_set cSet;
        FD_ZERO(&cSet);
        FD_SET(MasterSocket, &cSet);
        for (auto iter = SlaveSockets.begin();
             iter != SlaveSockets.end();
             iter++) {
            FD_SET(*iter, &cSet);
        }

        int max_fd = std::max(MasterSocket,
                              *std::max_element(SlaveSockets.begin(),
                                                SlaveSockets.end()));

        select(max_fd + 1, &cSet, NULL, NULL, NULL);

        for (auto iter = SlaveSockets.begin();
             iter != SlaveSockets.end();
             iter++) {

            if(FD_ISSET(*iter, &cSet)) {
                static char buffer[1024];
                int recvSize = recv(*iter,
                                    buffer,
                                    1024,
                                    MSG_NOSIGNAL);

                if ((recvSize == 0) && (errno !=  EAGAIN)) {
                    shutdown(*iter, SHUT_RDWR);
                    close(*iter);
                    SlaveSockets.erase(iter);
                } else if (recvSize != 0) {
                    send(*iter, buffer, recvSize, MSG_NOSIGNAL);
                }
            }
        }
        if(FD_ISSET(MasterSocket, &cSet)) {
            int SlaveSocket = accept(MasterSocket, 0, 0);
            set_non_block(SlaveSocket);
            SlaveSockets.insert(SlaveSocket);
        }
    }

    return 0;
}
