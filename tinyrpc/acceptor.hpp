#pragma once

#include "task.hpp"
#include "async_loop.hpp"
#include "socket.hpp"
#include "connection.hpp"
#include "worker.hpp"

Task<> tcp_acceptor(AsyncLoop& loop, mysocket& so) {
    int listenfd = so.create_socket();
    setNonBlock(listenfd);

    std::vector<Worker> workers(std::thread::hardware_concurrency());
    int curtid = 0;
    for (auto& worker : workers) {
        worker.run();
    }

    while (true) {
        auto [connfd, client] = co_await socket_accpet(loop, listenfd);
        fmt::print("New Connection: {}\n", connfd);

        workers[curtid].AddConn(connfd);
        curtid = (curtid + 1) % workers.size();
    }
}