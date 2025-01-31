# Converts Forenheits to Celcius

set(CPP_SOURCES
    converter.cpp
)

add_executable(converter ${CPP_SOURCES})
add_executable(test_converter test.cpp)
