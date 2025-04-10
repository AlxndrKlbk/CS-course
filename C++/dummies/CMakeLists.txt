cmake_minimum_required(VERSION 3.26)

project(dummies LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
cmake_policy(SET CMP0076 NEW)

add_subdirectory(main_utils)
add_subdirectory(multithreading)
add_subdirectory(bierne_straustrup)
add_subdirectory(old_cpp)
add_subdirectory(problems)
add_subdirectory(sockets/multiplexing)
