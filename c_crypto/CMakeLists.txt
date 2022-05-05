cmake_minimum_required(VERSION 3.10)
project(c_crypto C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(keygen src/keygen.c src/crypto.c src/util.c)
add_executable(encrypt src/encrypt.c src/crypto.c src/util.c)
add_executable(decrypt src/decrypt.c src/crypto.c src/util.c)

include_directories(include)

target_link_libraries(keygen PUBLIC sodium)
target_link_libraries(encrypt PUBLIC sodium)
target_link_libraries(decrypt PUBLIC sodium)
