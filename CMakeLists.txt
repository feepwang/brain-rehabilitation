cmake_minimum_required(VERSION 3.15.0)

project("Brain ReHabilitation")

option(BR_ENABLE_TESTS "Enable tests" OFF)
include(CTest)
enable_testing()

find_package(Threads REQUIRED)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(include)

add_subdirectory(src)
add_subdirectory(test)