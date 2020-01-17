
cmake_minimum_required(VERSION 3.15)

set(OS_VERSION "Linux")
if(${CMAKE_SYSTEM_NAME} MATCHES Darwin)
    set(OS_VERSION "MacOS")
elseif(${CMAKE_SYSTEM_NAME} MATCHES Windows)
    set(OS_VERSION "Windows")
endif()

project (ExEncoder)
#project(ExEncoder VERSION 1.0)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MT")
set(CMAKE_CXX_STANDARD 17)



add_definitions(-DCMAKEMACROSAMPLE=1)

message("----------------------------------------")
message("OS Type: ${OS_VERSION}")
message("OS Name: ${CMAKE_SYSTEM_NAME}")
message("CXX Standard: ${CMAKE_CXX_STANDARD}")
message("Source dir: ${CMAKE_SOURCE_DIR}")
message("Include path: ${CMAKE_INCLUDE_PATH}")
message("Cmake home dir: ${CMAKE_HOME_DIRECTORY}")
message("Cmake binary dir: ${CMAKE_BINARY_DIR}")
message("EXE output: ${EXECUTABLE_OUTPUT_PATH}")
message("Flags: ${CMAKE_CXX_FLAGS}")
message("Flags: ${CMAKE_C_FLAGS}")
message("Flags: ${TARGET}")
message("----------------------------------------")

add_executable(exencoder src/ExEncode.cpp)

TARGET_COMPILE_OPTIONS(exencoder PUBLIC "/MT$<$<CONFIG:Release>:>")