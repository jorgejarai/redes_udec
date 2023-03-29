#include <stdio.h>

#include "udp.h"

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "uso: %s <dirección> <puerto>\n", argv[0]);
        return 1;
    }

    char* host = argv[1];
    int port = atoi(argv[2]);
    if (port <= 0 || port > 65535) {
        fprintf(stderr, "%s: número de puerto inválido: %s\n", argv[0],
                argv[1]);
        return 1;
    }

    struct udp_socket_t socket;

    udp_connect(&socket, host, port);

    if (socket.fd < 0) {
        fprintf(stderr, "%s: no se pudo abrir el socket\n", argv[0]);
        return 1;
    }

    const char message[] = "¡Hola, señor Turner!";
    udp_write(&socket, &socket.addr, message, sizeof(message));

    char buf[1024];
    ssize_t read_bytes = udp_read(&socket, NULL, buf, sizeof(buf));
    if (read_bytes < 0) {
        fprintf(stderr, "%s: no se pudo leer del socket\n", argv[0]);
        return 1;
    }

    buf[read_bytes] = '\0';
    printf("El servidor dice: %s\n", buf);

    udp_close(&socket);

    return 0;
}
