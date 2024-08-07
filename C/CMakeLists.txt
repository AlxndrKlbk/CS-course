cmake_minimum_required(VERSION 3.5)

project(C_project LANGUAGES C)


add_subdirectory(sockets)

add_executable(c_test c_test.c)
