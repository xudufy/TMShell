cmake_minimum_required(VERSION 3.19)

project(TMShell)


set(CXX_STANDARD 14)

add_compile_options(/MD /wd4251) # We will always link to Release Mode dynamic msvcrt.

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
find_package(Boost 1.76.0 REQUIRED COMPONENTS beast filesystem system PATHS 3rdParty)
if (NOT Boost_FOUND)
  message(FATAL_ERROR "Fatal error: Boost (version >= 1.76) required.")
endif()

include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})

file(GLOB parser_source LIST_DIRECTORIES false CONFIGURE_DEPENDS parser/*.cpp)
file(GLOB tmshell_source LIST_DIRECTORIES false CONFIGURE_DEPENDS tmshell/*.cpp)
file(GLOB tmshelld_source LIST_DIRECTORIES false CONFIGURE_DEPENDS tmshelld/*.cpp)
file(GLOB common_source LIST_DIRECTORIES false CONFIGURE_DEPENDS common/*.cpp)

add_library(parser
    OBJECT
    ${parser_source}
)

add_executable(
    tmshell

    ${common_source}
    ${tmshell_source}
    $<TARGET_OBJECTS:parser>
)
target_link_libraries(tmshell ${Boost_LIBRARIES})

add_executable(
    tmshelld

    ${common_source}
    ${tmshelld_source}
    $<TARGET_OBJECTS:parser>
)
target_link_libraries(tmshelld ${Boost_LIBRARIES})