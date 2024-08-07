#include <unistd.h>

#include <stdio.h>
#include <stdbool.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc, char** argv) {

    int socketDescriptor = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    struct sockaddr_in sock_addr;
    sock_addr.sin_family = AF_INET;
    sock_addr.sin_port = htons(12345);
    sock_addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);

    int connected = connect(socketDescriptor,
            &sock_addr,
            sizeof(sock_addr));

    if (connected == -1) {
        printf("Not connected to server");
        return -1;
    }

    char buff[] = "ping";
    send(socketDescriptor, buff, 4, MSG_NOSIGNAL);
    recv(socketDescriptor, buff, 4, MSG_NOSIGNAL);

    shutdown(socketDescriptor, SHUT_RDWR);
    close(socketDescriptor);

    printf("%s\n", buff);

    return 0;
}
