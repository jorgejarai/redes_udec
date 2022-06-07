#ifndef UDP_H
#define UDP_H

#include <arpa/inet.h>
#include <netinet/in.h>

struct addr_t {
    struct sockaddr_in address;
    socklen_t size;
};

struct udp_socket_t {
    struct addr_t address;
    int sock;
};

void udp_server_init(struct udp_socket_t* server, int port);
void udp_client_init(struct udp_socket_t* client, const char* host, int port);

void udp_send(const struct udp_socket_t* socket, const struct addr_t* dest,
              const void* data, size_t size);
ssize_t udp_recv(const struct udp_socket_t* socket, struct addr_t* sender_addr,
                 void* buf, size_t max_size);

#endif  // UDP_H
