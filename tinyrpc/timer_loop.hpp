#pragma once

#include <coroutine>
#include <chrono>
#include <queue>
#include <optional>
#include <memory>
#include <fmt/core.h>
#include <unordered_map>

#include "task.hpp"
#include "epoll_loop.hpp"

using timePoint = std::chrono::system_clock::time_point;
using timeDuration = std::chrono::system_clock::duration;

struct TimerLoop {
    struct TimeEntry { // 用于定义小根堆
        timePoint mExpireTime;
        std::shared_ptr<Task<>> mPtr;
        int fd;
        bool operator < (const TimeEntry& x) const {
            return mExpireTime > x.mExpireTime;
        }
    };

    std::priority_queue<TimeEntry> TimerHeap;
    std::unordered_map<int, std::shared_ptr<Task<>>> Mapper;
    std::vector<int> toRemove;

    void AddTask(std::shared_ptr<Task<>> Ptr, int fd, timeDuration ExpireDuration) {
        //fmt::print("Add Timer Task: {}\n", fd);
        TimerHeap.push({std::chrono::system_clock::now() + ExpireDuration, Ptr, fd});
        Mapper[fd] = Ptr;
    }

    void RefreshTask(int fd, timeDuration ExpireDuration) {
        //fmt::print("Refresh Timer Task: {}\n", fd);
        TimerHeap.push({std::chrono::system_clock::now() + ExpireDuration, Mapper[fd], fd});
    }

    std::optional<std::chrono::system_clock::duration> run() {
        while (!TimerHeap.empty()) {
            auto nowTime = std::chrono::system_clock::now();
            auto& nowTop = TimerHeap.top();
            if (nowTop.mExpireTime < nowTime) {
                if (nowTop.mPtr.use_count() <= 2) {
                    //fmt::print("Called Time-out remove: {}\n", nowTop.fd);
                    toRemove.push_back(nowTop.fd);
                }
                TimerHeap.pop();
            }
            else {
                return nowTop.mExpireTime - nowTime;
            }
        }
        return std::nullopt;
    }

    TimerLoop &operator=(TimerLoop &&) = delete;

};