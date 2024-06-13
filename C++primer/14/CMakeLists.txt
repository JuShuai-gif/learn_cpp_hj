cmake_minimum_required(VERSION 3.5)
project(test1)
add_executable(test1 test1.cpp)

target_link_libraries(test1 pthread)