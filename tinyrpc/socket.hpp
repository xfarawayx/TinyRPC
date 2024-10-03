#pragma once

#include <arpa/inet.h>
#include <fcntl.h>
#include <sys/epoll.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>
#include <fmt/core.h>

#include "task.hpp"
#include "epoll_loop.hpp"

struct mysocket {
    struct addrinfo *addr;
    
    mysocket(const std::string& ip, const std::string& port) {
        int res = getaddrinfo(ip.c_str(), port.c_str(), NULL, &addr);
        if (res != 0) {
            std::cerr << "[Error] getaddrinfo " << gai_strerror(res) << std::endl;
            throw;
        }
    }

    int create_socket() {
        int sockfd = CHECK_CALL(socket, addr->ai_family, addr->ai_socktype, addr->ai_protocol);
        CHECK_CALL(bind, sockfd, addr->ai_addr, addr->ai_addrlen);
        CHECK_CALL(listen, sockfd, SOMAXCONN);
        return sockfd;
    }

    int connect_to_server() {
        int sockfd = CHECK_CALL(socket, addr->ai_family, addr->ai_socktype, addr->ai_protocol);
        CHECK_CALL(connect, sockfd, addr->ai_addr, addr->ai_addrlen);
        return sockfd;
    }

    ~mysocket() {
        freeaddrinfo(addr);
    }
};

struct clientaddr {
    struct sockaddr addr;
    socklen_t addrlen = sizeof(addr);
};

Task<std::tuple<int, clientaddr>> socket_accpet(EpollLoop& loop, int fd) {
    clientaddr client;
    co_await wait_file_event(loop, fd, EPOLLIN);
    int nfd = CHECK_CALL(accept4, fd, &client.addr, &client.addrlen, SOCK_NONBLOCK);
    co_return {nfd, client};
}

