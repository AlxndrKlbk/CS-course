cmake_minimum_required(VERSION 3.5)

project(dummies LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(dummies main.cpp)
add_executable(converter converter/converter.cpp)
add_executable(romans problems/romans_to_int/romans.cpp )
add_executable(romans_2 problems/romans_to_int/romans_2.cpp )
add_executable(max_wealth problems/max_wealth/max_wealth.cpp )
add_executable(reducer problems/reduce_to_zero/reducer.cpp )

install(TARGETS dummies
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
