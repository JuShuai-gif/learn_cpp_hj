cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 14)

project(RAII_pointer)

add_executable(vector_test vector_test.cpp)

add_executable(raii_test raii_test.cpp)

add_executable(constructor constructor.cpp)

add_executable(smartpoint smartpoint.cpp)

add_executable(test test.cpp)