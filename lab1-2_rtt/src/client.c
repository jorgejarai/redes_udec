#include <stdio.h>

#include "rudp.h"
#include "udp.h"

int main(void) {
    // Creamos una conexión UDP
    struct udp_socket_t client;
    udp_client_init(&client, "127.0.0.1", 10000);

    char msg[5] = "Hola";  // Mensaje a enviar
    char buf[256];         // Búfer para respuesta

    // Enviamos nuestro mensaje y esperamos una respuesta
    rudp_client_send_recv(&client, &client.address, &msg, sizeof(msg), &buf,
                          sizeof(buf));

    // Imprimimos la respuesta
    printf("%s\n", buf);

    return 0;
}
