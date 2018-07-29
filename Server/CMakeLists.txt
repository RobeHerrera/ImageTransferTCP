cmake_minimum_required(VERSION 3.12)
project(Server)

set(CMAKE_CXX_STANDARD 14)

include_directories(inc)
include_directories(src)

add_executable(Server
        inc/node.h
        inc/socket_manager.h
        inc/tcp_server.h
        inc/utils.h
        src/demo_Server.cpp
        src/node.cpp
        src/socket_manager.cpp
        src/tcp_server.cpp)
