
cmake_minimum_required(VERSION 3.16)

set(OS_VERSION "Linux")
if(${CMAKE_SYSTEM_NAME} MATCHES Darwin)
    set(OS_VERSION "MacOS")
elseif(${CMAKE_SYSTEM_NAME} MATCHES Windows)
    set(OS_VERSION "Windows")
endif()

project (ExEncoder)
project(ExEncoder VERSION 1.0)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_CXX_STANDARD 17)

#set(CMAKE_CXX_FLAGS "-std=c++17")



message("----------------------------------------")
message("OS Type: ${OS_VERSION}")
message("OS Name: ${CMAKE_SYSTEM_NAME}")
message("CXX Standard: ${CMAKE_CXX_STANDARD}")
message("Source dir: ${CMAKE_SOURCE_DIR}")
message("Include path: ${CMAKE_INCLUDE_PATH}")
message("Cmake home dir: ${CMAKE_HOME_DIRECTORY}")
message("Cmake binary dir: ${CMAKE_BINARY_DIR}")
message("EXE output: ${EXECUTABLE_OUTPUT_PATH}")
message("----------------------------------------")

add_executable(exenc src/ExEncode.cpp)
