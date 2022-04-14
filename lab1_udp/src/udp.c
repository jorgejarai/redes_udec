#include "udp.h"

#include <netdb.h>
#include <string.h>
#include <unistd.h>

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

void udp_write(struct udp_socket_t* conn, const char* data, size_t len) {
    sendto(conn->fd, data, len, 0, (struct sockaddr*)&conn->addr,
           sizeof(conn->addr));
}

size_t udp_read(struct udp_socket_t* conn, struct sockaddr_in* sender,
                const char* buf, size_t max_len) {
    unsigned int addr_len = sizeof(*sender);

    return recvfrom(conn->fd, (void*)buf, max_len, 0, (struct sockaddr*)sender,
                    &addr_len);
}
