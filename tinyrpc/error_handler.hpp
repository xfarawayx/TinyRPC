#pragma once

#include <iostream>
#include <cerrno>
#include <system_error>
#include <fmt/core.h>

int checkError(const char* msg, int res) {
    if (res == -1) [[unlikely]] {
        fmt::print("[Error] {} {}", msg, strerror(errno));
        throw std::system_error(errno, std::system_category());
    }
    return res;
}

ssize_t checkErrorIO(const char* msg, ssize_t res) {

    if (res == -1) {
        if (errno == ECONNRESET) {
            fmt::print("[Reset] {}: {}.\n", msg, strerror(errno));
            res = -2;
        }
        else if (errno == EWOULDBLOCK) {
            fmt::print("[Block] {}: {}.\n", msg, strerror(errno));
            res = 0;
        }
        else {
            fmt::print("[ErrorNonBlock] {} {}", msg, strerror(errno));
            throw std::system_error(errno, std::system_category());
        }
    }
    return res;
}

#define CHECK_CALL(func, ...) checkError(#func, func(__VA_ARGS__))
#define CHECK_CALL_IO(func, ...) checkErrorIO(#func, func(__VA_ARGS__))