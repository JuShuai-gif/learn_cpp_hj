cmake_minimum_required(VERSION 3.5)
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_STANDARD 14)

project(GongZhongHao)

add_executable(move_forward move_forward.cpp)

add_executable(noeccept_test noeccept_test.cpp)

add_executable(std_endl_test std_endl_test.cpp)

add_executable(Unsigned_Integer_Overflow Unsigned_Integer_Overflow.cpp)

add_executable(iterator_failure iterator_failure.cpp)

