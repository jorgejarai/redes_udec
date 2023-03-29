cmake_minimum_required(VERSION 3.10)
project(lab2 C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(udp_server src/server.c src/udp.c)
add_executable(udp_client src/client.c src/udp.c)

target_include_directories(udp_server PRIVATE include)
target_include_directories(udp_client PRIVATE include)

