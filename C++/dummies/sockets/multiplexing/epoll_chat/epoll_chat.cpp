#include <iostream>
#include <set>
#include <algorithm>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/epoll.h>
#include <arpa/inet.h>

#define MAX_EVENTS 32

using namespace std;

int set_nonblock(int fd)
{
    int flags;
#if defined(O_NONBLOCK)
    if (-1 == (flags = fcntl(fd, F_GETFL, 0)))
        flags = 0;
    return fcntl(fd, F_SETFL, flags | O_NONBLOCK);
#else
    flags = 1;
    return ioctl(fd, FIOBIO, &flags);
#endif
}

string socketIP(int socket)
{
    struct sockaddr_in SockAddr;
    uint len = sizeof(struct sockaddr_in);
    getsockname(socket, (struct sockaddr *)&SockAddr, &len);
    return inet_ntoa(SockAddr.sin_addr);
}

int main()
{
    int MasterSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    set<int> SlaveSockets;

    struct sockaddr_in SockAddr;
    SockAddr.sin_family = AF_INET;
    SockAddr.sin_port = htons(12345);
    SockAddr.sin_addr.s_addr = htonl(INADDR_ANY);   // 0.0.0.0
    bind(MasterSocket, (struct sockaddr *)&SockAddr, sizeof(SockAddr));

    set_nonblock(MasterSocket);
    listen(MasterSocket, SOMAXCONN);

    // Create descriptor
    int EPoll = epoll_create1(0);

    // Create events structure for Master socket
    struct epoll_event MasterEvent;
    MasterEvent.data.fd = MasterSocket;
    MasterEvent.events = EPOLLIN;

    // Register Master socket in the descriptor
    epoll_ctl(EPoll, EPOLL_CTL_ADD, MasterSocket, &MasterEvent);

    //
    while(true) {
        struct epoll_event Events[MAX_EVENTS];
        // epoll_wait returns only real number of events from OS to app
        int N = epoll_wait(EPoll, Events, MAX_EVENTS, -1);
        // ...so no need to query ALL sockets, only with coming events
        for(uint i = 0; i < N; i++) {
            if(Events[i].data.fd == MasterSocket) {
                int SlaveSocket = accept(MasterSocket, 0, 0);
                set_nonblock(SlaveSocket);
                // Create events structure for slave socket
                struct epoll_event Event;
                Event.data.fd = SlaveSocket;
                Event.events = EPOLLIN;
                // Register slave socket in the descriptor
                epoll_ctl(EPoll, EPOLL_CTL_ADD, SlaveSocket, &Event);
                // Add socket to the set
                // Send message to all new client is connected
                static string connectMessage =
                    socketIP(SlaveSocket) + ": client is connected\n";
                for(auto it = SlaveSockets.begin(); it != SlaveSockets.end(); it++)
                    send(*it, connectMessage.c_str(), connectMessage.length(), MSG_NOSIGNAL);
                // Add socket only after adding
                SlaveSockets.insert(SlaveSocket);
            } else {
                static char Buffer[1024];
                int RecvResult = recv(Events[i].data.fd, Buffer, 1024, MSG_NOSIGNAL);
                if(RecvResult == 0 && errno != EAGAIN) {
                    // Send messages to all client is disconnected first
                    static string disconnectMessage =
                        socketIP(Events[i].data.fd) + ": client is disconnected\n";
                    for(auto it = SlaveSockets.begin(); it != SlaveSockets.end(); it++)
                        if(*it != Events[i].data.fd)
                            send((*it), disconnectMessage.c_str(), disconnectMessage.length(),
                                 MSG_NOSIGNAL);
                    // Then close socket with error
                    shutdown(Events[i].data.fd, SHUT_RDWR);
                    close(Events[i].data.fd);
                    SlaveSockets.erase(Events[i].data.fd);  // Remove from the set
                } else if(RecvResult > 0) {
                    for(auto it = SlaveSockets.begin(); it != SlaveSockets.end(); it++)
                        // Send to all clients except sending
                        if(*it != Events[i].data.fd) {
                            string str(Buffer);
                            string message = socketIP(*it) + ": " + str.substr(0, RecvResult);
                            send((*it), message.c_str(), message.length(), MSG_NOSIGNAL);
                        }
                }
            }
        }
    }

    return 0;
}
