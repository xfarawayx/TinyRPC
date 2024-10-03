#include "task.hpp"
#include "buffer.hpp"
#include "async_loop.hpp"
#include "socket.hpp"
#include "protocol.hpp"
#include "service.hpp"
#include "acceptor.hpp"

#include <google/protobuf/service.h>
#include "calc.pb.h"

class CalculatorServiceImpl : public CalculatorService {
public:
    void Add(google::protobuf::RpcController* controller,
             const AddRequest* request,
             AddResponse* response,
             google::protobuf::Closure* done) {
        int result = request->a() + request->b();
        fmt::print("Add: {} + {} = {}\n", request->a(), request->b(), result);
        response->set_result(result);
    }
};

AsyncLoop &getLoop() {
    static AsyncLoop loop;
    return loop;
}

int main() {
    RegisterService("Add", std::make_shared<CalculatorServiceImpl>());
    mysocket so("127.0.0.1", "8080");
    Task<> T = tcp_acceptor(getLoop(), so);
    fmt::print("Listening on 127.0.0.1:8080...\n");
    T.mCoroutine.resume();
    while (!T.mCoroutine.done()) {
        getLoop().runOnce(true);
    }
}