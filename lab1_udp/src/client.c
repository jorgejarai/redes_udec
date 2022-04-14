#include <stdio.h>

#include "udp.h"

int main(int argc, char* argv[]) {
    struct udp_socket_t socket;

    udp_connect(&socket, "localhost", 10000);

    if (socket.fd < 0) {
        fprintf(stderr, "%s: could not open socket\n", argv[0]);
        return 1;
    }

    const char message[] = "Hola, mundo!";
    udp_write(&socket, message, sizeof(message));

    return 0;
}
