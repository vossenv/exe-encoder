
cmake_minimum_required(VERSION 3.16)

file(REMOVE ../build/*)
file(MAKE_DIRECTORY ../build)

set(TNAME "exencoder")
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_CXX_STANDARD 17)

project (${TNAME})
add_executable(${TNAME})
include_directories(libs)

target_include_directories(${TNAME} PUBLIC include)
if(${CMAKE_CXX_COMPILER_ID} STREQUAL MSVC)
    TARGET_COMPILE_OPTIONS(${TNAME} PUBLIC "/MT$<$<CONFIG:Release>:>")
endif()

target_sources(${TNAME} PRIVATE 
    libs/base64.cpp
    exencode/App.cpp
    exencode/BinaryFile.cpp
    exencode/Converter.cpp
    exencode/ErrorHandler.cpp
    exencode/Util.cpp
)

 if(WIN32)
    add_definitions(-DISWINDOWS)
 elseif(APPLE)
    add_definitions(-DISMACOS)    
 elseif(UNIX)
    add_definitions(-DISLINUX)
 endif()

message("----------------------------------------")
message("Target: ${TNAME}")
message("OS Name: ${CMAKE_SYSTEM_NAME}")
message("CXX Standard: ${CMAKE_CXX_STANDARD}")
message("Compiler: ${CMAKE_CXX_COMPILER_ID}")
message("Source dir: ${CMAKE_SOURCE_DIR}")
message("Cmake home dir: ${CMAKE_HOME_DIRECTORY}")
message("Cmake binary dir: ${CMAKE_BINARY_DIR}")
message("EXE output: ${EXECUTABLE_OUTPUT_PATH}")
message("CXX Flags: ${CMAKE_CXX_FLAGS}")
message("Sources: ")
get_target_property(TS ${TNAME} SOURCES)
foreach(l ${TS}) 
    string(REPLACE "/" ";" l ${l})
    list (GET l -1 file)
    message(" - ${file}")
endforeach(l)
message("----------------------------------------")


#if (WIN32)
#    set(CMAKE_SHARED_LINKER_FLAGS /MANIFEST:NO)
#endif()
#add_custom_command(
#    TARGET ${TNAME}
#    POST_BUILD COMMAND "mt.exe" -manifest \"${EXECUTABLE_OUTPUT_PATH}\\${TNAME}.exe.manifest\" -outputresource:\"${EXECUTABLE_OUTPUT_PATH}\\${TNAME}.exe\"\;\#2
#    COMMENT "Adding custom manifest containing MSVCRT80 dependency..." )

#FILE(GLOB sources ${CMAKE_SOURCE_DIR}/source/*.cc)
#ADD_EXECUTABLE(mycode ${sources})