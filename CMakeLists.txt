cmake_minimum_required(VERSION 3.5)

# 项目信息
project(learn_cpp_hj VERSION 1.0)

# 设置C++标准
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 指定编译类型为Release
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

# 指定源码目录
#set(SOURCE_DIR ${CMAKE_SOURCE_DIR}/src)

# 将源文件添加到可执行文件
#add_executable(MyExecutable ${SOURCE_DIR}/main.cpp)

# 指定安装目录
#install(TARGETS MyExecutable DESTINATION bin)

add_subdirectory(2_0)

add_subdirectory(公众号)

add_subdirectory(c++primer)

add_subdirectory(eventloop)

add_subdirectory(learn_gdb)

add_subdirectory(os)

add_subdirectory(peng)