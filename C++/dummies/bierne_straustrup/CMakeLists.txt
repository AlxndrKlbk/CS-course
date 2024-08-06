
add_executable(pointers_to_massives pointers_to_massives/pointers_to_massives.cpp)
add_executable(initialize_list initializer_list/initializer_list.cpp)
add_executable(pointers_copy pointers_copy/poiters_copy.cpp)
add_executable(init_copy_test
    init_copy_test/init_copy_test.cpp
    init_copy_test/virtual_inheritance.cpp
    init_copy_test/base_with_pure_virtual_implemented.cpp
)
add_executable(animals animals/animals.cpp)
add_executable(mstring mstring/mstring.cpp mstring/mstring.hpp)
add_executable(lambda lambda/lambda.cpp)
add_executable(structured_bindings structured_bindings/structured_bindings.cpp)
add_executable(exception exception/exception.cpp)
add_executable(enable_if_like_concept intraspection_meta_functions/enable_if_like_concept.cpp)
add_executable(intraspection intraspection_meta_functions/intraspection.cpp)

add_subdirectory(allocators)
