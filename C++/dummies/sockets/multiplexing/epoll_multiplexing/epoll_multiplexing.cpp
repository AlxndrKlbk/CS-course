#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/epoll.h>

#ifndef MAX_EVENTS
#define MAX_EVENTS 32
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
    int masterSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    struct sockaddr_in SockAddr;
    SockAddr.sin_family = AF_INET;
    SockAddr.sin_port = htons(12345);
    SockAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    bind(masterSocket, reinterpret_cast<sockaddr *>(&SockAddr), sizeof(SockAddr));

    set_non_block(masterSocket);

    listen(masterSocket, SOMAXCONN);

    int ePoll = epoll_create1(0);

    struct epoll_event event;
    event.data.fd = masterSocket;
    event.events = EPOLLIN;
    epoll_ctl(ePoll, EPOLL_CTL_ADD, masterSocket, &event);

    while (true) {
        epoll_event events[MAX_EVENTS];
        int N = epoll_wait(ePoll, events, MAX_EVENTS, -1);
        for (int i = 0; i < N; i++) {
            if (events[i].data.fd == masterSocket) {
                int slaveSocket = accept(masterSocket, 0, 0);
                set_non_block(slaveSocket);

                struct epoll_event event;
                event.data.fd = slaveSocket;
                event.events = EPOLLIN;
                epoll_ctl(ePoll, EPOLL_CTL_ADD, masterSocket, &event);
                epoll_ctl(ePoll, EPOLL_CTL_ADD, slaveSocket, &event);
            } else {
                static char buffer[1024];
                int recvResult = recv(events[i].data.fd, buffer, 1024, MSG_NOSIGNAL);
                if ((recvResult == 0) && (errno != EAGAIN)) {
                    shutdown(events[i].data.fd, SHUT_RDWR);
                    close(events[i].data.fd);
                } else if (recvResult > 0) {
                    send(events[i].data.fd,
                         buffer,
                         recvResult,
                         MSG_NOSIGNAL);
                }
            }
        }
    }

    return 0;
}
