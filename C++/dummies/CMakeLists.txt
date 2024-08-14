cmake_minimum_required(VERSION 3.5)

project(dummies LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
cmake_policy(SET CMP0076 NEW)

add_subdirectory(main_utils)
add_subdirectory(multithreading)
add_subdirectory(bierne_straustrup)
add_subdirectory(old_cpp)
add_subdirectory(sockets/multiplexing)
add_subdirectory(problems/about_math/)

add_executable(dummies main.cpp)
add_executable(converter problems/converter/converter.cpp)
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
add_executable(palindromic_substr2 problems/palindromic_substr/palindromic_substr2.cpp)
add_executable(int_to_bin problems/int_to_bin/int_to_bin.cpp)
add_executable(duplicates_in_str problems/duplicates_in_str/duplicates_in_str.cpp)
add_executable(serializable_list_node
    problems/serializable_list_node/main.cpp
    problems/serializable_list_node/serializable_list_node.cpp)
add_executable(deepest_node problems/deepest_node_bin_tree/deepest_node.cpp)
add_executable(three_sum problems/three_sum/three_sum.cpp)
add_executable(phone_number_digits problems/phone_number_digits/phone_number_digits.cpp)
add_executable(remove_nth_elem_node_list problems/remove_nth_elem_node_list/remove_nth_elem_node_list.cpp )
add_executable(reverse_int problems/reverse_int/reverse_int.cpp )
add_executable(valid_brackets problems/valid_brackets/valid_brackets.cpp )
add_executable(z_pattern problems/z_pattern/z_pattern.cpp )
add_executable(my_atoi problems/my_atoi/my_atoi.cpp )
add_executable(merge_two_sorted_list problems/merge_two_sorted_list/merge_two_sorted_list.cpp)
add_executable(parenthesis problems/parenthesis/parenthesis.cpp)
add_executable(vector_filter_duplicate problems/vector_filter_duplicates/vector_filter_duplicates.cpp)
add_executable(anagrams_str problems/anagrams_str/anagrams_str.cpp)
add_executable(anagram_groups problems/anagram_groups/anagram_groups.cpp)
add_executable(polynom_derivative problems/polynom_derivative/polynom_derivative.cpp)
add_executable(ladder_to_a problems/ladder_to_a/ladder_to_a.cpp)

add_executable(two_sum problems/two_sum/two_sum.cpp)
target_link_libraries(two_sum PUBLIC main_utils)
target_include_directories(two_sum PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/main_utils"
)

target_include_directories( ${PROJECT_NAME} PUBLIC
    problems/serializable_list_node
)

target_sources( ${PROJECT_NAME} PUBLIC
    problems/serializable_list_node/serializable_list_node.cpp
)

install(TARGETS dummies
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
