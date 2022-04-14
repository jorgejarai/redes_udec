#ifndef UDP_H
#define UDP_H

#include <arpa/inet.h>
#include <stdint.h>
#include <stdlib.h>

struct udp_socket_t {
    int fd;
    struct sockaddr_in addr;
};

void udp_listen(struct udp_socket_t* conn, uint16_t port);
void udp_connect(struct udp_socket_t* conn, const char* host, uint16_t port);

void udp_write(struct udp_socket_t* conn, const char* data, size_t len);
size_t udp_read(struct udp_socket_t* conn, struct sockaddr_in* sender,
                const char* buf, size_t max_len);

#endif  // UDP_H
