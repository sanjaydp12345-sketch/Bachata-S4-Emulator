cmake_minimum_required(VERSION 3.22.1)
project(bachata_emulator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(bachata_emulator SHARED native_bridge.cpp)

target_compile_options(bachata_emulator PRIVATE -Wall -Wextra -Werror=return-type)
target_link_libraries(bachata_emulator android log)
