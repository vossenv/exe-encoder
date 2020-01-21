
cmake_minimum_required(VERSION 3.16)

file(REMOVE ../build/*)
file(MAKE_DIRECTORY ../build)



set(TNAME "exencoder")
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_CXX_STANDARD 17)

project (${TNAME})

set(BOOST_ROOT C:\\boost_1_72_0\\boost)
set(BOOST_LIBRARYDIR C:\\boost_1_72_0\\lib64-msvc-12.0)
set(BOOST_INCLUDEDIR C:\\boost_1_72_0)
set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost 1.55.0 COMPONENTS thread)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS}) 
    LINK_DIRECTORIES(${Boost_LIBRARY_DIRS})

    add_executable(${TNAME})
    include_directories(libs)
    target_include_directories(${TNAME} PUBLIC include)
    target_sources(${TNAME} PRIVATE 
        libs/base64.cpp
        libs/CLI11.hpp
        exencode/App.cpp
        exencode/BinaryFile.cpp
        exencode/Converter.cpp
        exencode/ErrorHandler.cpp
        exencode/Util.cpp
    )


    target_link_libraries(${TNAME} ${Boost_LIBRARIES})
else()
    message(STATUS "Fail  asdasd!")
    EXIT()
endif()



get_target_property(TARGET_SOURCES ${TNAME} SOURCES)
#if(${CMAKE_CXX_COMPILER_ID} STREQUAL MSVC)
#    TARGET_COMPILE_OPTIONS(${TNAME} PUBLIC "/MT$<$<CONFIG:Release>:>")
#endif()

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
message("Include path: ${CMAKE_INCLUDE_PATH}")
message("Cmake home dir: ${CMAKE_HOME_DIRECTORY}")
message("Cmake binary dir: ${CMAKE_BINARY_DIR}")
message("EXE output: ${EXECUTABLE_OUTPUT_PATH}")
message("CXX Flags: ${CMAKE_CXX_FLAGS}")
message("Sources: ${TARGET_SOURCES}")
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