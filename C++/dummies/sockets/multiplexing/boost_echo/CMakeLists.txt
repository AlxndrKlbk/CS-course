
find_package(Boost REQUIRED COMPONENTS
    date_time filesystem iostreams
)

add_executable(boost_echo boost_echo.cpp)

if(Boost_FOUND)
    message("Boost libs founded: " ${Boost_LIBRARIES})
    target_link_libraries(boost_echo  ${Boost_LIBRARIES})
else(NOT Boost_FOUND)
    error("Boost libraries not found.")
endif()
