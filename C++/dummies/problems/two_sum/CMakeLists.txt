
add_executable(two_sum two_sum.cpp)
target_link_libraries(two_sum PUBLIC main_utils)
target_include_directories(two_sum PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/main_utils"
)

install(TARGETS two_sum
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
