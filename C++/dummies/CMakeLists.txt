cmake_minimum_required(VERSION 3.5)

project(dummies LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(dummies main.cpp)
add_executable(converter converter/converter.cpp)

install(TARGETS dummies
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
