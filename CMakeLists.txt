cmake_minimum_required(VERSION 3.30)
project(OpenPort)

set(CMAKE_CXX_STANDARD 20)

add_executable(OpenPort main.cpp)
target_link_libraries(OpenPort ws2_32)
