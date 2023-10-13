PROJECT(rpc)
message("Project name: ${PROJECT_NAME}")

CMAKE_MINIMUM_REQUIRED (VERSION 3.16)
# SET(CMAKE_CXX_FLAGS "-g -Wall -Werror -std=c++11")

cmake_policy(SET CMP0068 NEW)

set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)
set(CMAKE_DISABLE_SOURCE_CHANGES ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CONAN_DISABLE_CHECK_COMPILER ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_VERBOSE_MAKEFILE OFF)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
list(APPEND CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR})

set(CMAKE_BUILD_TYPE Release)
set(QT_CREATOR_SKIP_CONAN_SETUP ON)

include(conan)

conan_cmake_configure(REQUIRES
                        grpc/1.50.1
                        protobuf/3.21.9
                    GENERATORS
                        cmake
                        cmake_find_package
                    IMPORTS "bin, *.dll -> ./bin"
                    IMPORTS "lib, *.dylib* -> ./bin"
                        )

conan_cmake_autodetect(settings)
list(APPEND settings compiler=gcc)
list(APPEND settings compiler.version=10)
list(APPEND settings compiler.libcxx=libstdc++11)

conan_cmake_install(PATH_OR_REFERENCE .
                    #BUILD missing
                    REMOTE conancenter
                    SETTINGS ${settings})

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)


include(FindProtobuf)
find_package(Protobuf REQUIRED)

message("\n--[protobuf_INCLUDE]: ${protobuf_INCLUDE_DIR}")

# proto files dir
ADD_SUBDIRECTORY(proto)

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})
INCLUDE_DIRECTORIES(${protobuf_INCLUDE_DIR})


ADD_EXECUTABLE(${PROJECT_NAME} main.cpp)
TARGET_LINK_LIBRARIES(${PROJECT_NAME} proto ${protobuf_LIBRARIES})

include(InstallRequiredSystemLibraries)

include(Packing)

