cmake_minimum_required(VERSION 3.15)
project(opencv_demo)

set(CMAKE_CXX_STANDARD 17)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR})
list(APPEND CMAKE_PREFIX_PATH ${CMAKE_BINARY_DIR})

include(cmake/conan.cmake)

conan_cmake_configure(
        REQUIRES
        opencv/4.5.5
        GENERATORS cmake_find_package
        IMPORTS "res, haarcascades* -> cascades"
        IMPORTS "res, lbpcascades* -> cascades"
)

conan_cmake_autodetect(settings)

conan_cmake_install(PATH_OR_REFERENCE .
        BUILD missing
        SETTINGS ${settings})

find_package(opencv REQUIRED)

add_subdirectory(examples)
