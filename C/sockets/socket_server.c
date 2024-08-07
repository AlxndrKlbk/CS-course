#include <unistd.h>

#include <stdio.h>
#include <stdbool.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>


int main (int argc, char** argv) {

    int master_socket = socket(
        AF_INET /*IPv4 */,
        SOCK_STREAM /* TCP protocol */,
        IPPROTO_TCP);
    struct sockaddr_in sock_addr;
    sock_addr.sin_family = AF_INET;
    sock_addr.sin_port = htons (12345);
    sock_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    int write_descriptor = bind(master_socket,
         (struct socaddr *)(&sock_addr),
         sizeof(sock_addr));

    if (write_descriptor == -1) {
        printf("Not binded socket to write");
        return -1;
    }

    int listen_descriptor = listen(master_socket, SOMAXCONN);

    if (listen_descriptor == -1) {
        printf("Not binded socket to listen");
        return -2;
    }

    while(true) {
        int slave_socket = accept(master_socket, 0, 0);

        if (slave_socket == -1) {
            printf("Not binded socket to listen");
            continue;
        }

        char buffer[5] = {0, 0, 0, 0, 0};
        recv(slave_socket, buffer, 4, MSG_NOSIGNAL);
        send(slave_socket, buffer, 4, MSG_NOSIGNAL);

        shutdown(slave_socket, SHUT_RDWR);
        close(slave_socket);
        printf("%s\n", (char*)buffer);
    }

    return 0;
}
