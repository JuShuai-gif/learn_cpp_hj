
include_directories(${CMAKE_SOURCE_DIR}/tinySTL/include)

add_executable(test test/test.cpp)

add_executable(test1 test/test1.cpp)

add_executable(test2 test/test2.cpp)

#add_executable(test3 test/test3.cpp)

add_executable(test4 test/test4.cpp)

add_executable(tinySTL_vector_test test/vector_test.cpp)

add_executable(tinySTL_deque_test test/deque_test.cpp)