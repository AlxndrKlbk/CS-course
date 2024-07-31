set(LIB_HEADERS
    main_func_utils.hpp
)

set(LIB_SOURCES
    main_func_utils.cpp
)

add_library(main_utils SHARED ${LIB_SOURCES})
set_target_properties(main_utils PROPERTIES PUBLIC_HEADER ${LIB_HEADERS})

