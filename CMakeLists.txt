cmake_minimum_required(VERSION 3.15)
project(opencv_demo)

set(CMAKE_CXX_STANDARD 17)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR})
list(APPEND CMAKE_PREFIX_PATH ${CMAKE_BINARY_DIR})

find_package(opencv REQUIRED)

add_subdirectory(examples)
