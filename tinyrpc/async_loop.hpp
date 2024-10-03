#pragma once

#include "epoll_loop.hpp"
#include "timer_loop.hpp"
#include <set>
#include <optional>

struct AsyncLoop {

    void AddClosed(int fd) {
        closedfd.insert(fd);
    }

    bool runOnce(bool isMainLoop) {
        auto timeout = mTimerLoop.run();
        if (!mTimerLoop.toRemove.empty()) {
            for (auto &x : mTimerLoop.toRemove) {
                if (closedfd.find(x) != closedfd.end()) {
                    closedfd.erase(x);
                }
                else {
                    mEpollLoop.RemoveListener(x);
                }
                close(x);
                //fmt::print("(Debug) {}\n", mTimerLoop.Mapper[x].use_count());
                mTimerLoop.Mapper.erase(x);
            }
            mTimerLoop.toRemove.clear();
        }

        if (timeout == std::nullopt && !isMainLoop) {
           return false;
        }

        mEpollLoop.run(timeout);
        return true;
    }

    operator TimerLoop&() {
        return mTimerLoop;
    }
    operator EpollLoop&() {
        return mEpollLoop;
    }

private:
    TimerLoop mTimerLoop;
    EpollLoop mEpollLoop;
    std::set<int> closedfd;
};