CMAKE_MINIMUM_REQUIRED(VERSION 3.16)

PROJECT(resources)

SET (CMAKE_CXX_STANDARD 17)
SET (CMAKE_CXX_STANDARD_REQUIRED ON)

SET(RESOURCES_HEADERS
    include/resource_storage.h
    )

if(NOT DEFINED CMAKE_OBJCOPY)
    message(FATAL_ERROR "Can`t find CMAKE_OBJCOPY command" )
endif(NOT DEFINED CMAKE_OBJCOPY)

set(RESOURCE_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/resource_files")
message(STATUS "Resources dir: " ${RESOURCE_DIRECTORY})

set(PROJECT_EMBED_OBJ_FILES "")
set(POINTERS_FOR_EMBED_FILES "")
file(GLOB EMBED_FILE_LIST ${RESOURCE_DIRECTORY}/*)

set(LINK_TYPE "extern char ")

If(NOT DEFINED TARGET_FORMAT)
    set(TARGET_FORMAT "elf64-x86-64")
endif(NOT DEFINED TARGET_FORMAT)

If(NOT DEFINED TARGET_ARCHITECTURE)
        set(TARGET_ARCHITECTURE "i386")
endif(NOT DEFINED TARGET_ARCHITECTURE)

foreach(FILENAME ${EMBED_FILE_LIST})
    get_filename_component(FILENAME_ONLY ${FILENAME} NAME)
    get_filename_component(FILEPATH_ONLY ${FILENAME} PATH)

    # Create object file
    add_custom_command(OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/${FILENAME_ONLY}.o
                       WORKING_DIRECTORY ${FILEPATH_ONLY}
                       COMMAND ${CMAKE_OBJCOPY}
                       ARGS -I binary -O ${TARGET_FORMAT} -B ${TARGET_ARCHITECTURE} ${FILENAME_ONLY} ${CMAKE_CURRENT_BINARY_DIR}/${FILENAME_ONLY}.o)

    # Add path to new object resource file to the objective resource files list
    list(APPEND PROJECT_EMBED_OBJ_FILES ${CMAKE_CURRENT_BINARY_DIR}/${FILENAME_ONLY}.o)

    if(EXISTS ${CMAKE_CURRENT_BINARY_DIR}/${FILENAME_ONLY}.o)
        message(STATUS "Objcopy'ing ${FILENAME}")
    endif(EXISTS ${CMAKE_CURRENT_BINARY_DIR}/${FILENAME_ONLY}.o)

    # Create source file configuration
    string(REGEX REPLACE "[^a-zA-Z0-9а-яА-Я]" "_" OBJECTIVE_NAME ${FILENAME_ONLY})

    set(START_PTR "_binary_${OBJECTIVE_NAME}_start")
    set(END_PTR "_binary_${OBJECTIVE_NAME}_end")

    set(POINTERS_FOR_EMBED_FILES ${POINTERS_FOR_EMBED_FILES} "\n\n\t${LINK_TYPE} ${START_PTR}")
    set(POINTERS_FOR_EMBED_FILES ${POINTERS_FOR_EMBED_FILES} "\n\t${LINK_TYPE} ${END_PTR}")

    set(FILL_IN_POINTERS ${FILL_IN_POINTERS} "\n\tfile_pointers.insert(std::pair<std::string, FilePtr>(\"${FILENAME_ONLY}\",FilePtr(&${START_PTR}, &${END_PTR})))")

endforeach(FILENAME)

set(POINTERS_FOR_EMBED_FILES "${POINTERS_FOR_EMBED_FILES};")
set(FILL_IN_POINTERS "${FILL_IN_POINTERS};")

# Set path to the source file
set(SOURCE_FILES "${CMAKE_CURRENT_BINARY_DIR}/resource_storage.cpp")

# configure source file
configure_file("${CMAKE_CURRENT_SOURCE_DIR}/resource_storage.cpp.template"
               ${SOURCE_FILES})

#Create library and alias
add_library(${PROJECT_NAME}
    STATIC
        ${RESOURCES_HEADERS}
        ${SOURCE_FILES}
        ${PROJECT_EMBED_OBJ_FILES})

target_include_directories(${PROJECT_NAME}
    PUBLIC
        include/)

add_library(resources::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

add_subdirectory(tests/)
