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
add_executable(bit_accessor problems/bit_accessor/bit_accessor.cpp)
add_executable(palindrome problems/palindrome/palindrome.cpp)
add_executable(ransome_note problems/ransome_note/ransome_note.cpp)
add_executable(fizz_buzz problems/fizz_buzz/fizz_buzz.cpp)
add_executable(del_middle_node problems/del_middle_node/del_middle_node.cpp)
add_executable(k_weakest_rows_matrix problems/k_weakest_rows_matrix/k_weakest.cpp)

install(TARGETS dummies
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
