cmake_minimum_required(VERSION 3.21)

project(br LANGUAGES CXX)

option(BR_BUILD_TESTS "build the tests for the br project" ON)
if (BR_BUILD_TESTS)
    enable_testing()
endif()

# fmt is much faster and more usable than iostream
find_package(fmt CONFIG REQUIRED)

include_directories("${CMAKE_SOURCE_DIR}/include")
add_subdirectory(src)

if(BR_BUILD_TESTS)
    add_subdirectory(tests)
endif()