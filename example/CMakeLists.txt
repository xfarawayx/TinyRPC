cmake_minimum_required(VERSION 3.16)
project(hellocmake LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

find_package(Protobuf REQUIRED)

# 如果Protobuf被找到，包含其目录
if(PROTOBUF_FOUND)
  include_directories(${PROTOBUF_INCLUDE_DIRS})
  link_directories(${PROTOBUF_LIBRARY_DIRS})
  #message(STATUS "Protobuf include dirs: ${PROTOBUF_INCLUDE_DIRS}")
  #message(STATUS "Protobuf libraries: ${PROTOBUF_LIBRARIES}")
  #message(STATUS "Protobuf protoc executable: ${PROTOBUF_PROTOC_EXECUTABLE}")
endif()

add_executable(server server.cpp calc.pb.cc)
add_executable(client client.cpp calc.pb.cc)

target_link_libraries(server PUBLIC ${PROTOBUF_LIBRARIES})
target_link_libraries(client PUBLIC ${PROTOBUF_LIBRARIES})

target_include_directories(server PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../tinyrpc)
target_include_directories(client PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../tinyrpc)

find_package(fmt REQUIRED)
target_link_libraries(server PUBLIC fmt::fmt)
target_link_libraries(client PUBLIC fmt::fmt)
