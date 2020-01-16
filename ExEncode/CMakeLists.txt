
cmake_minimum_required(VERSION 3.16)


# UNIX, WIN32, WINRT, CYGWIN, APPLE are environment variables as flags set by default system
if(UNIX)
    message("This is a ${CMAKE_SYSTEM_NAME} system")
elseif(WIN32)
    message("This is a Windows System")
endif()
# or use MATCHES to see if actual system name 
# Darwin is Apple's system name
if(${CMAKE_SYSTEM_NAME} MATCHES Darwin)
    message("This is a ${CMAKE_SYSTEM_NAME} system")
elseif(${CMAKE_SYSTEM_NAME} MATCHES Windows)
    message("This is a Windows System")
endif()


project (ExEncoder)
project(ExEncoder VERSION 1.0)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_CXX_STANDARD 17)

#set(CMAKE_CXX_FLAGS "-std=c++17")



message("----------------------------------------")
message("CXX Standard: ${CMAKE_CXX_STANDARD}")
message("Source dir: ${CMAKE_SOURCE_DIR}")
message("Include path: ${CMAKE_INCLUDE_PATH}")
message("Cmake home dir: ${CMAKE_HOME_DIRECTORY}")
message("Cmake binary dir: ${CMAKE_BINARY_DIR}")
message("EXE output: ${EXECUTABLE_OUTPUT_PATH}")
message("----------------------------------------")

add_executable(exenc src/ExEncode.cpp)
