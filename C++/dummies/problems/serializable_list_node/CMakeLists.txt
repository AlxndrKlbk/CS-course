
set(CPP_SOURCES
    main.cpp
    serializable_list_node.cpp
)
set(CPP_HEADERS
    serializable_list_node.hpp
)

add_executable(serializable_list_node ${CPP_SOURCES} ${CPP_HEADERS})
