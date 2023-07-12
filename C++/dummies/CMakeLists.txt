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
add_executable(negative_in_matrix problems/negative_in_matrix/negative_amount.cpp)
add_executable(find_target problems/find_target/find_target.cpp)
add_executable(find_target_2 problems/find_target/find_target_2.cpp)
add_executable(add_two_num problems/add_two_num/add_two_num.cpp)
add_executable(add_two_num_2_list problems/add_two_num_2_list/add_two_num_2_list.cpp)
add_executable(add_two_num_2_list_shared problems/add_two_num_2_list/add_two_num_2_list_shared.cpp)
add_executable(biggest_prefix problems/biggest_prefix/biggest_prefix.cpp)
add_executable(biggest_substr_uniq_chars problems/biggest_substr/biggest_substr_uniq_chars.cpp)
add_executable(contain_most_water problems/contain_most_water/contain_most_water.cpp)
add_executable(int_to_roman problems/int_to_roman/int_to_roman.cpp)
add_executable(int_to_roman2 problems/int_to_roman/int_to_roman2.cpp)
add_executable(mid_of_array problems/mid_of_arrays/mid_of_arrays.cpp)
add_executable(palindromic_substr problems/palindromic_substr/palindromic_substr.cpp)


install(TARGETS dummies
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
