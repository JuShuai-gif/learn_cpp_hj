cmake_minimum_required(VERSION 3.5)

# 设置编译选项
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 选择Debug编译模式
set(CMAKE_BUILD_TYPE "Debug")

# 设置Debug模式下的编译选项
#set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -Wall -g")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -ggdb -gstabs+")
# 设置Release模式下的编译选项
#set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3 -Wall")

project(example_1)

add_subdirectory(backward-cpp)

add_executable(example_1 example_1.cpp)


target_sources(example_1 PUBLIC ${BACKWARD_ENABLE})
add_backward(example_1)
