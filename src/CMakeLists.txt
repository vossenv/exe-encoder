
cmake_minimum_required(VERSION 3.15)
file(MAKE_DIRECTORY ../build)

project (exencoder)
add_executable(exencoder)

include_directories(libs)
target_include_directories(exencoder PUBLIC exencode/include)

set(target_sources
    App.cpp
    Converter.cpp
)

list(TRANSFORM target_sources PREPEND "exencode/src/")
target_sources(exencoder PRIVATE ${target_sources})

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_CXX_STANDARD 17)

if(${CMAKE_CXX_COMPILER_ID} STREQUAL MSVC)
    TARGET_COMPILE_OPTIONS(exencoder PUBLIC "/MT$<$<CONFIG:Release>:>")
endif()

 if(WIN32)
    add_definitions(-DPLATFORM="windows")
 elseif(APPLE)
    add_definitions(-DPLATFORM="macos")
 elseif(UNIX)
    add_definitions(-DPLATFORM="linux")
 endif()

message("----------------------------------------")
message("OS Name: ${CMAKE_SYSTEM_NAME}")
message("CXX Standard: ${CMAKE_CXX_STANDARD}")
message("Compiler: ${CMAKE_CXX_COMPILER_ID}")
message("Source dir: ${CMAKE_SOURCE_DIR}")
message("Include path: ${CMAKE_INCLUDE_PATH}")
message("Cmake home dir: ${CMAKE_HOME_DIRECTORY}")
message("Cmake binary dir: ${CMAKE_BINARY_DIR}")
message("EXE output: ${EXECUTABLE_OUTPUT_PATH}")
message("CXX Flags: ${CMAKE_CXX_FLAGS}")
message("Sources: ${target_sources}")
message("----------------------------------------")


#if (WIN32)
#    set(CMAKE_SHARED_LINKER_FLAGS /MANIFEST:NO)
#endif()
#add_custom_command(
#    TARGET exencoder
#    POST_BUILD COMMAND "mt.exe" -manifest \"${EXECUTABLE_OUTPUT_PATH}\\exencoder.exe.manifest\" -outputresource:\"${EXECUTABLE_OUTPUT_PATH}\\exencoder.exe\"\;\#2
#    COMMENT "Adding custom manifest containing MSVCRT80 dependency..." )

#FILE(GLOB sources ${CMAKE_SOURCE_DIR}/source/*.cc)
#ADD_EXECUTABLE(mycode ${sources})