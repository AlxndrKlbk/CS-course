cmake_minimum_required(VERSION 3.16)

add_executable(test_storage
    test_storage.cpp)

target_link_libraries(test_storage PUBLIC resources::resources)
