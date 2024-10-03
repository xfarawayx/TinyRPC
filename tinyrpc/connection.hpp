#pragma once

#include "buffer.hpp"
#include "protocol.hpp"
#include "async_loop.hpp"
#include "timer_loop.hpp"
#include "task.hpp"
#include "service.hpp"

Task<> handle_connection(AsyncLoop& loop, int connfd) {
    Buffer buf;

    while (true) {
        // --- Read ---
        std::string serviceName, messageStr;

        do {
            auto n = co_await read_file(loop, connfd, buf);
            fmt::print("Get messege from {}, Length: {}, n = {}\n", connfd, buf.readAble(), n);

            if (n <= 0) { //Reset
                fmt::print("[Read] Connection {} has been shutdown by peer.\n", connfd);
                loop.AddClosed(connfd);
                co_return ;
            }

            static_cast<TimerLoop&>(loop).RefreshTask(connfd, std::chrono::seconds(10));

        } while (!decode(&buf, serviceName, messageStr));

        fmt::print("Get Service Name: {}\n", serviceName);

        // --- Excute ---
        std::string res = ExecuteService(serviceName, messageStr);
        
        // --- Send ---
        auto n = co_await write_file(loop, connfd, res);

        if (n < 0) { //Reset
            fmt::print("[Write] Connection {} has been shutdown by peer.\n", connfd);
            loop.AddClosed(connfd);
            co_return ;
        }

        fmt::print("Send messege to {}\n", connfd);
    }

    //close(connfd);
}