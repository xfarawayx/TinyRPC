#pragma once

#include <string>
#include <memory>
#include <map>

#include <google/protobuf/message.h>
#include <google/protobuf/service.h>

using service_ptr = std::shared_ptr<google::protobuf::Service>;

std::map<std::string, service_ptr> ServiceMap;

void RegisterService(const std::string& serviceName, service_ptr service) {
    ServiceMap[serviceName] = service;
}

std::string ExecuteService(const std::string& serviceName, std::string& req) {
    service_ptr service = ServiceMap[serviceName];
    const google::protobuf::MethodDescriptor* method = service->GetDescriptor()
                                                        ->FindMethodByName(serviceName);
    google::protobuf::Message* request = service->GetRequestPrototype(method).New();
    google::protobuf::Message* response = service->GetResponsePrototype(method).New();

    request->ParseFromString(req);

    service->CallMethod(method, nullptr, request, response, nullptr);

    std::string responseData;
    response->SerializeToString(&responseData);   

    return responseData;   
}