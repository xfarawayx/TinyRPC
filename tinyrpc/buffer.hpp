#pragma once

#include <vector>
#include <memory>
#include <string>
#include <string.h>
#include <sys/uio.h>
#include <unistd.h>

struct Buffer {

public:

    static const size_t kInitialSize = 1024;    

    explicit Buffer(size_t initialSize = kInitialSize)
        :   mBuffer(initialSize),
            mReadIndex(0),
            mWriteIndex(0)
        {}

    int readAble() {
        return mWriteIndex - mReadIndex;
    }

    int writeAble() {
        return mBuffer.size() - mWriteIndex;
    }

    int readIndex() {
        return mReadIndex;
    }

    int writeIndex() {
        return mWriteIndex;
    }

    // 返回缓冲区中可读数据的起始地址
    const char* peek() const {
        return begin() + mReadIndex;
    }

    // 读取 len 字节后复位
    void retrive(size_t len) {
        if (len < readAble()) {
            mReadIndex += len;
        }
        else {
            mReadIndex = mWriteIndex = 0;
        }
    }

    std::string readAsString(size_t len) {
        std::string res(peek(), len);
        retrive(len);
        return res;
    }

    std::string readAllAsString() {
        return readAsString(readAble());
    }

    int32_t getInt32(bool _retrive = false) {
        if (readAble() < sizeof(int32_t)) {
            return -1;
        }

        int32_t res = 0;
        memcpy(&res, peek(), sizeof(res));

        if (_retrive) {
            retrive(sizeof(res));
        }
        return res;
    }

    // 将 data 追加到缓冲区最后
    void append(const char* data, size_t len) {
        if (writeAble() < len) {
            makeSpace(len);
        }
        std::copy(data, data + len, begin() + writeIndex());
        mWriteIndex += len;
    }

    void append(const std::string& str) {
        append(str.data(), str.size());
    }

    void appendInt32(int32_t num) {
        //num = htonl(num);
        append(reinterpret_cast<const char*>(&num), sizeof(num));
    }

    ssize_t readFd(int fd) {
        char extrabuf[65536] = {0};

        struct iovec vec[2];
        
        vec[0].iov_base = begin() + writeIndex();
        vec[0].iov_len = writeAble();

        vec[1].iov_base = extrabuf;
        vec[1].iov_len = sizeof(extrabuf);

        const int maxWrite = writeAble();
        const int iovcnt = (maxWrite < sizeof(extrabuf)) ? 2 : 1;
       
        const ssize_t n = readv(fd, vec, iovcnt);
        if (n < 0) {
            return n;
        }
        else if (n <= maxWrite) {
            mWriteIndex += n;
        }
        else {
            mWriteIndex = mBuffer.size();
            append(extrabuf, n - maxWrite);
        }
        return n;
    }

    ssize_t writeFd(int fd) {
        ssize_t n = write(fd, peek(), readAble());
        return n;
    }

private:
    std::vector<char> mBuffer;
    int mReadIndex;
    int mWriteIndex;

    // 获取buffer_起始地址
    char* begin() {
        return &(*mBuffer.begin());
    }

    const char* begin() const {
        return &(*mBuffer.begin());
    }

    // 扩容操作
    void makeSpace(size_t len) {
        if (writeAble() + readIndex() < len) {
            mBuffer.resize(writeAble() + len);
        }
        else {
            const size_t readable = readAble();
            std::copy(begin() + readIndex(), begin() + writeIndex(), begin());
            mReadIndex = 0;
            mWriteIndex = readable;
        }
    }
};