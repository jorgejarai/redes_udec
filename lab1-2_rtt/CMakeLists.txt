cmake_minimum_required(VERSION 3.10)
project(lab1-2_rtt C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(server src/server.c src/udp.c src/rtt.c src/rudp.c)
add_executable(client src/client.c src/udp.c src/rtt.c src/rudp.c)

include_directories(include)

