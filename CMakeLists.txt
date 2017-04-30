cmake_minimum_required(VERSION 2.8)

project(bin2mif)
add_executable(${PROJECT_NAME} "main.cpp")

set(CMAKE_CXX_FLAGS "-Wall -Wextra -std=c++11")
