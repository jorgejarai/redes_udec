#include <stdio.h>

#include "udp.h"

int main(int argc, char *argv[]) {
    struct udp_socket_t socket;

    udp_listen(&socket, 10000);

    if (socket.fd < 0) {
        fprintf(stderr, "%s: could not open socket\n", argv[0]);
        return 1;
    }

    while (1) {
        struct sockaddr_in client_addr;
        char buf[1024];

        ssize_t read_bytes = udp_read(&socket, &client_addr, buf, sizeof(buf));
        if (read_bytes < 0) {
            fprintf(stderr, "%s: could not read from socket\n", argv[0]);
            return 1;
        }

        buf[read_bytes] = '\0';
        printf("%s says: %s\n", inet_ntoa(client_addr.sin_addr), buf);
    }

    return 0;
}
