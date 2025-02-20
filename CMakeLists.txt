cmake_minimum_required(VERSION 3.30)
project(OpenPort)

set(CMAKE_CXX_STANDARD 20)

add_executable(OpenPort main.cpp
        include/program_options.h
        include/target_ipv4.h
        target_ipv4.cpp
        program_options.cpp
        include/scan_tcp.h
        scan_tcp.cpp)
target_link_libraries(OpenPort ws2_32)
