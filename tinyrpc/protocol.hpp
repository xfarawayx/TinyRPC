#pragma once

#include "buffer.hpp"

void encode(Buffer* buf, const std::string& serviceName, const std::string& messageStr) {
    int32_t nameLen = static_cast<int32_t>(serviceName.size());
    int32_t messageLen = static_cast<int32_t>(messageStr.size());
    int32_t packetLen = sizeof(int32_t) * 2 + nameLen + messageLen;

    buf->appendInt32(packetLen);
    buf->appendInt32(nameLen);
    buf->append(serviceName.data(), nameLen);
    buf->append(messageStr.data(), messageLen);
}

bool decode(Buffer* buf, std::string& serviceName, std::string& messageStr) {
    if (buf->readAble() < sizeof(int32_t)) {
        return false;
    }
    
    int32_t packetLen = buf->getInt32(false);
    if (buf->readAble() < packetLen) {
        return false;
    }
    buf->getInt32(true);

    int32_t nameLen = buf->getInt32(true);
    serviceName = buf->readAsString(nameLen);

    int32_t messageLen = packetLen - sizeof(int32_t) * 2 - nameLen;
    messageStr = buf->readAsString(messageLen);

    return true;
}