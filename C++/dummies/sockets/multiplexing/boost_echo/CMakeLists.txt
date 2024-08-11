
find_package(Boost REQUIRED COMPONENTS
    date_time filesystem iostreams)

add_executable(boost_echo boost_echo.cpp)

if(Boost_FOUND)
    message("message!!! " ${Boost_LIBRARIES} ":end!!")
    target_link_libraries(boost_echo  ${Boost_LIBRARIES})
endif()
