#include "udp.h"

#include <netdb.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>

/**
 * @brief	Inicializa un servidor UDP
 *
 * @param[out]  conn: un puntero para guardar la información del nuevo socket
 * @param	port: el puerto a escuchar
 *
 * @retval	Ninguno
 */
void udp_listen(struct udp_socket_t* conn, uint16_t port) {
    conn->fd = socket(AF_INET, SOCK_DGRAM, 0);

    if (conn->fd < 0) {
        return;
    }

    memset(&conn->addr, 0, sizeof(conn->addr));
    conn->addr.sin_family = AF_INET;
    conn->addr.sin_addr.s_addr = htonl(INADDR_ANY);
    conn->addr.sin_port = htons(port);

    if (bind(conn->fd, (struct sockaddr*)&conn->addr, sizeof(conn->addr)) < 0) {
        close(conn->fd);
        conn->fd = -1;
        return;
    }
}

/**
 * @brief	Conecta a un servidor UDP
 *
 * @param[out]  conn: un puntero para guardar la información del nuevo socket
 * @param       host: el nombre o dirección IP del servidor
 * @param	port: el puerto del servidor
 *
 * @retval	Ninguno
 */
void udp_connect(struct udp_socket_t* conn, const char* host, uint16_t port) {
    conn->fd = socket(AF_INET, SOCK_DGRAM, 0);

    if (conn->fd < 0) {
        return;
    }

    memset(&conn->addr, 0, sizeof(conn->addr));
    conn->addr.sin_family = AF_INET;
    conn->addr.sin_port = htons(port);

    struct addrinfo* res;
    if (getaddrinfo(host, NULL, NULL, &res) != 0) {
        close(conn->fd);
        conn->fd = -1;
        return;
    }

    memcpy(&conn->addr.sin_addr, &((struct sockaddr_in*)res->ai_addr)->sin_addr,
           sizeof(conn->addr.sin_addr));

    if (connect(conn->fd, (struct sockaddr*)&conn->addr, sizeof(conn->addr)) <
        0) {
        close(conn->fd);
        conn->fd = -1;
        return;
    }

    freeaddrinfo(res);
}

/**
 * @brief  Envía un mensaje UDP
 *
 * @param  fd: el descriptor del socket
 * @param  addr: la dirección del destinatario
 * @param  data: el mensaje a enviar
 * @param  len: la longitud del mensaje
 *
 * @retval Ninguno
 */
void udp_write(int fd, struct sockaddr_in* addr, const char* data, size_t len) {
    sendto(fd, data, len, 0, (struct sockaddr*)addr, sizeof(*addr));
}

/**
 * @brief	Recibe un mensaje UDP
 *
 * @param       conn: un puntero almacenando la información del socket
 * @param[out]  sender: un puntero para guardar la información de la dirección
 *		del remitente (opcional)
 * @param	buf: un puntero para guardar el mensaje recibido
 * @param	max_len: la longitud máxima del mensaje
 *
 * @retval	La longitud del mensaje recibido
 */
size_t udp_read(struct udp_socket_t* conn, struct sockaddr_in* sender,
                const char* buf, size_t max_len) {
    unsigned int addr_len = sizeof(*sender);

    return recvfrom(conn->fd, (void*)buf, max_len, 0, (struct sockaddr*)sender,
                    &addr_len);
}
