
find_package(Libevent REQUIRED)
add_executable(libevent_echo libevent_echo.c)
target_link_libraries(libevent_echo libevent::core)
