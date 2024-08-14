# start lib declaration
set(LIB_HEADERS
    calc_integral/calc_integral.hpp
)

set(LIB_SOURCES
    calc_integral/calc_integral.cpp
)

add_library(math_methods SHARED ${LIB_HEADERS} ${LIB_SOURCES})
target_include_directories(math_methods PUBLIC calc_integral)
set_target_properties(math_methods PROPERTIES PUBLIC_HEADER ${LIB_HEADERS})
# end for lib declaration

add_executable(calc_integral calc_integral/calc_integral.hpp calc_integral/calc_integral.cpp)

add_executable(func_even_check func_even_check/func_even_check.cpp func_even_check/func_even_check.hpp)
target_link_libraries(func_even_check PUBLIC math_methods)
