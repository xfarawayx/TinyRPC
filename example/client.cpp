// Only for test.

#include "error_handler.hpp"
#include "calc.pb.h"
#include "buffer.hpp"
#include "protocol.hpp"
#include "socket.hpp"

int main(int argc, char **argv) {
    mysocket so("127.0.0.1", "8080");
    int sockfd = so.connect_to_server();
    if (sockfd == -1) {
        fmt::print("Connect Failed!");
        return 0;
    }

    srand(time(NULL));
    for (int i = 1; i <= 10; ++i) {
        int m_a = rand() % 20, m_b = rand() % 20;
        std::string requestData;
        AddRequest request;
        request.set_a(m_a);
        request.set_b(m_b);
        request.SerializeToString(&requestData);

        Buffer buf;
        encode(&buf, "Add", requestData);

        //if (write(sockfd, requestData.c_str(), requestData.size()) == -1) {
        auto n = buf.writeFd(sockfd);
        if (n == -1) {
            fmt::print("Fail to send message.\n");
            close(sockfd);
            return 0;
        }
        else {
            fmt::print("Send Message: {}\n", n);
        }

        sleep(3);

        char buf1[1024];
        if (read(sockfd, buf1, sizeof(buf1)) == -1) {
            fmt::print("Fail to get message.\n");
            close(sockfd);
            return 0;
        }

        std::string responseData = std::string(buf1);
        AddResponse response;
        response.ParseFromString(responseData);

        fmt::print("{} + {} = {}\n", m_a, m_b, response.result());
    }

    close(sockfd);
}