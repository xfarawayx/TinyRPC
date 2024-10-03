#pragma once

#include <chrono>
#include <sys/epoll.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <optional>
#include <span>

#include "task.hpp"
#include "buffer.hpp"
#include "error_handler.hpp"

struct EpollFilePromise : Promise<void> {

    int mFileNo;
    uint32_t mEvents;

    auto get_return_object() {
        return std::coroutine_handle<EpollFilePromise>::from_promise(*this);
    }

    EpollFilePromise &operator = (EpollFilePromise&& ) = delete;

    // ~EpollFilePromise() {
    //      fmt::print("Call Destruct {} {} {}\n", mFileNo,
    //                  (int)mEvents, static_cast<const void*>(this));
    // }

};

struct EpollLoop {

    int epfd = CHECK_CALL(epoll_create1, 0);
    struct epoll_event mEventBuf[64];

    EpollLoop &operator=(EpollLoop &&) = delete;
    ~EpollLoop() {
        close(epfd);
    }

    void AddListener(EpollFilePromise& promise, int ctl = EPOLL_CTL_ADD) {
        //fmt::print("Add Listener {}\n", promise.mFileNo);
        struct epoll_event event;
        event.events = promise.mEvents;
        event.data.ptr = &promise;
        CHECK_CALL(epoll_ctl, epfd, ctl, promise.mFileNo, &event);
    }

    void RemoveListener(int fileNo) {
        CHECK_CALL(epoll_ctl, epfd, EPOLL_CTL_DEL, fileNo, NULL);
    }

    void run(std::optional<std::chrono::system_clock::duration> timeout) {

        int timeoutInMs = -1;
        if (timeout) {
            timeoutInMs =
                std::chrono::duration_cast<std::chrono::milliseconds>(*timeout).count();
        }

        int res = CHECK_CALL(epoll_wait, epfd, mEventBuf, 64, timeoutInMs);

        for (int i = 0; i < res; ++i) {
            // 取出先前保存的 promise 指针，将其从 epoll 中删除后转成协程回调
            auto &promise = *(EpollFilePromise *)mEventBuf[i].data.ptr;
            CHECK_CALL(epoll_ctl, epfd, EPOLL_CTL_DEL, promise.mFileNo, NULL);
            std::coroutine_handle<EpollFilePromise>::from_promise(promise).resume();
        }
    }

};

struct EpollFileAwaiter {

    EpollLoop& mLoop;
    int mFileNo;
    uint32_t mEvents;

    bool await_ready() const noexcept { return false; }

    void await_suspend(std::coroutine_handle<EpollFilePromise> coroutine) {
        auto& promise = coroutine.promise();
        promise.mFileNo = mFileNo;
        promise.mEvents = mEvents;
        mLoop.AddListener(promise);
    }

    void await_resume() const noexcept { }

};

Task<void, EpollFilePromise> wait_file_event(EpollLoop& loop, int fd, uint32_t events) {
    // 在 Awaiter 协程被放入 loop 监听
    // 若被取出直接返回到父协程 wait_file_event，然后返回父协程
    co_await EpollFileAwaiter(loop, fd, events);
}

Task<int> read_file(EpollLoop& loop, int fd, std::span<char> buffer) {
    co_await wait_file_event(loop, fd, EPOLLIN | EPOLLRDHUP);
    co_return CHECK_CALL_IO(read, fd, buffer.data(), buffer.size());
}

Task<int> write_file(EpollLoop& loop, int fd, const std::span<char> buffer) {
    co_await wait_file_event(loop, fd, EPOLLOUT | EPOLLHUP);
    co_return CHECK_CALL_IO(write, fd, buffer.data(), buffer.size());
}

Task<ssize_t> read_file(EpollLoop& loop, int fd, Buffer& buf) {
    co_await wait_file_event(loop, fd, EPOLLIN | EPOLLRDHUP);
    co_return CHECK_CALL_IO(buf.readFd, fd);
}

Task<ssize_t> write_file(EpollLoop& loop, int fd, Buffer& buf) {
    co_await wait_file_event(loop, fd, EPOLLOUT | EPOLLHUP);
    co_return CHECK_CALL_IO(buf.writeFd, fd);
}

void setNonBlock(int fd) {
    int attr = 1;
    CHECK_CALL(ioctl, fd, FIONBIO, &attr);
}