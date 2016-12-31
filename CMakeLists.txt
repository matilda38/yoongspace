cmake_minimum_required(VERSION 3.5)
project(untitled2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES Network/socket_pr_final.c)
add_executable(untitled2 ${SOURCE_FILES})