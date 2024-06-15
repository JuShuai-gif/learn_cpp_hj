
find_package(Threads REQUIRED)

add_executable(00_time 00_time.cpp)

add_executable(01_thread 01_thread.cpp)
target_link_libraries(01_thread PUBLIC Threads::Threads)

add_executable(02_thread 02_thread.cpp)
target_link_libraries(02_thread PUBLIC Threads::Threads)

add_executable(03_thread 03_thread.cpp)
target_link_libraries(03_thread PUBLIC Threads::Threads)

add_executable(04_thread 04_thread.cpp)
target_link_libraries(04_thread PUBLIC Threads::Threads)

add_executable(05_thread 05_thread.cpp)
target_link_libraries(05_thread PUBLIC Threads::Threads)

add_executable(06_thread 06_thread.cpp)
target_link_libraries(06_thread PUBLIC Threads::Threads)

add_executable(07_thread 07_thread.cpp)
target_link_libraries(07_thread PUBLIC Threads::Threads)

add_executable(08_thread 08_thread.cpp)
target_link_libraries(08_thread PUBLIC Threads::Threads)

add_executable(09_thread 09_thread.cpp)
target_link_libraries(09_thread PUBLIC Threads::Threads)

add_executable(10_thread 10_thread.cpp)
target_link_libraries(10_thread PUBLIC Threads::Threads)