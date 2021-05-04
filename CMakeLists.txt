cmake_minimum_required(VERSION 3.19)

project(TMShell)


set(CXX_STANDARD 14)

add_compile_options(/MD /MP /W4 /wd4458 /wd4996 /wd4251) # We will always link to Release Mode dynamic msvcrt.

add_definitions(-DTEST_SERVER) 

#for antlr 4 cpp runtime
set(ANTLR_PATH ${CMAKE_CURRENT_SOURCE_DIR}/3rdParty/antlr)
add_compile_options(/UANTLR4CPP_EXPORT)
add_definitions(/DANTLR4CPP_STATIC)
include_directories(${ANTLR_PATH}/include)
link_libraries(${ANTLR_PATH}/antlr_runtime.lib)

#generate Parser
set_property( DIRECTORY APPEND PROPERTY CMAKE_CONFIGURE_DEPENDS ${ARGV} ${CMAKE_CURRENT_SOURCE_DIR}/grammar/TMSlang.g4)
execute_process(COMMAND java -jar ${ANTLR_PATH}/antlr-4.9.2-complete.jar -Dlanguage=Cpp -visitor -no-listener -o parser -package tmshell ${CMAKE_CURRENT_SOURCE_DIR}/grammar/TMSlang.g4
WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
COMMAND_ERROR_IS_FATAL ANY)   

#for boost
set(Boost_USE_DEBUG_LIBS        OFF) # We will always link to Release Mode dynamic msvcrt
set(Boost_USE_RELEASE_LIBS       ON) # We will always link to Release Mode dynamic msvcrt
set(Boost_USE_STATIC_LIBS        ON)
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME    OFF)
set(Boost_USE_DEBUG_RUNTIME     OFF)
set(Boost_COMPILER vc142)
set(Boost_ADDITIONAL_VERSIONS "1.76" "1.76.0" "1.78" "1.78.0" "1.79" "1.79.0")
find_package(Boost 1.76.0 REQUIRED COMPONENTS filesystem system PATHS 3rdParty)
if (NOT Boost_FOUND)
  message(FATAL_ERROR "Fatal error: Boost (version >= 1.76) required.")
endif()

include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})
link_libraries(${Boost_LIBRARIES})

file(GLOB parser_source LIST_DIRECTORIES false CONFIGURE_DEPENDS parser/*.cpp)
file(GLOB tmshell_source LIST_DIRECTORIES false CONFIGURE_DEPENDS tmshell/*.cpp)
file(GLOB tmshelld_source LIST_DIRECTORIES false CONFIGURE_DEPENDS tmshelld/*.cpp)
file(GLOB common_source LIST_DIRECTORIES false CONFIGURE_DEPENDS common/*.cpp)

list(REMOVE_ITEM tmshelld_source ${CMAKE_CURRENT_SOURCE_DIR}/tmshelld/main.cpp) #in order to build tests.

add_definitions(-DTMSHELLD_OUTPUT_TO_CONSOLE)

add_library(parser
    OBJECT
    ${parser_source}
)
target_compile_options(parser PRIVATE /wd4100)

add_executable(
    tmshell

    ${common_source}
    ${tmshell_source}
    $<TARGET_OBJECTS:parser>
)

add_library(
    tmshelld_obj
    OBJECT

    ${common_source}
    ${tmshelld_source}
)

add_executable(
    tmshelld

    tmshelld/main.cpp
    $<TARGET_OBJECTS:parser>
    $<TARGET_OBJECTS:tmshelld_obj>
)

add_executable(
    time_func_test

    test/time_func_test.cpp
    $<TARGET_OBJECTS:parser>
    $<TARGET_OBJECTS:tmshelld_obj>
)

add_executable(
    windows_test

    test/windows_test.cpp
    $<TARGET_OBJECTS:parser>
    $<TARGET_OBJECTS:tmshelld_obj>
)

add_executable(
    action_test

    test/action_test.cpp
    $<TARGET_OBJECTS:parser>
    $<TARGET_OBJECTS:tmshelld_obj>
)
