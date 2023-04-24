cmake_minimum_required(VERSION 3.15)
project(opencv_demo)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenCV REQUIRED)

add_subdirectory(examples)
