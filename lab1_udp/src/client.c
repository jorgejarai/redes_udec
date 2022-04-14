#include <stdio.h>

#include "udp.h"

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "usage: %s <host> <port>\n", argv[0]);
        return 1;
    }

    char* host = argv[1];
    int port = atoi(argv[2]);
    if (port <= 0) {
        fprintf(stderr, "%s: invalid port number: %s\n", argv[0], argv[1]);
        return 1;
    }

    struct udp_socket_t socket;

    udp_connect(&socket, host, port);

    if (socket.fd < 0) {
        fprintf(stderr, "%s: could not open socket\n", argv[0]);
        return 1;
    }

    const char message[] = "Hola, mundo!";
    udp_write(&socket, message, sizeof(message));

    return 0;
}
