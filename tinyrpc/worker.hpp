#pragma once

#include <thread>
#include <mutex>
#include <vector>
#include <queue>
#include <algorithm>
#include <condition_variable>

#include "task.hpp"
#include "async_loop.hpp"
#include "timer_loop.hpp"
#include "connection.hpp"

struct Worker {
public:
    void run() {
        th = std::thread([this] {

            while (true) {
                while (loop.runOnce(false)) {
                    std::lock_guard<std::mutex> lck(mtx_queue);
                    if (!connections.empty()) break;
                }

                std::unique_lock<std::mutex> lck(mtx_queue);
                cv.wait(lck, [this] {return !connections.empty(); });
                int connfd = connections.front();
                connections.pop();
                lck.unlock();

                std::shared_ptr<Task<>> ptr = std::make_shared<Task<>>
                                                    (handle_connection(loop, connfd));
                static_cast<TimerLoop&>(loop).AddTask(ptr, connfd, std::chrono::seconds(10));

                ptr->mCoroutine.resume();
            }
        });
    }

    void AddConn(int connid) {
        std::unique_lock<std::mutex> lck(mtx_queue);
        connections.push(connid);
        lck.unlock();
        cv.notify_all();
    }

    std::thread th;
    std::queue<int> connections;
    std::mutex mtx_queue;
    std::condition_variable cv;

    AsyncLoop loop;
};