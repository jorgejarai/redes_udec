cmake_minimum_required(VERSION 3.14)
project(c_crypto C)

include(FetchContent)

FetchContent_Declare(Sodium
    GIT_REPOSITORY https://github.com/robinlinden/libsodium-cmake.git
    GIT_TAG 99f14233eab1d4f7f49c2af4ec836f2e701c445e # HEAD as of 2022-05-28
)
set(SODIUM_DISABLE_TESTS ON)
FetchContent_MakeAvailable(Sodium)

set(CMAKE_C_STANDARD 11)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(keygen src/keygen.c src/crypto.c src/util.c)
add_executable(encrypt src/encrypt.c src/crypto.c src/util.c)
add_executable(decrypt src/decrypt.c src/crypto.c src/util.c)

include_directories(include)

target_link_libraries(keygen PRIVATE sodium)
target_link_libraries(encrypt PRIVATE sodium)
target_link_libraries(decrypt PRIVATE sodium)
