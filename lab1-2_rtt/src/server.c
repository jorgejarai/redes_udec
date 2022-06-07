#include <stdio.h>

#include "rudp.h"
#include "udp.h"

int main(void) {
    // Levantamos el servidor
    struct udp_socket_t server;
    udp_server_init(&server, 10000);

    while (1) {
        // Aquí guardamos la IP del cliente
        struct addr_t client_addr;

        // Búfer para guardar el mensaje
        char buf[256];

        // Esperamos algún mensaje y guardamos la IP
        // del remitente
        rudp_server_recv(&server, &client_addr, buf, sizeof(buf));

        // Imprimimos el mensaje
        printf("%s\n", buf);

        // Respondemos con otro
        char msg[5] = "Chao";
        rudp_server_send(&server, &client_addr, &msg, sizeof(msg));
    }

    return 0;
}
