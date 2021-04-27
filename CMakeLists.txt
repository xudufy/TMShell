cmake_minimum_required(VERSION 3.12)

project(TMShell)


set(CXX_STANDARD 14)

add_compile_options(/MD /wd4251 /wd4286) # Because antlr.lib is compiled in release mode, linking to MD

#for antlr 4 cpp runtime
set(ANTLR_PATH ${CMAKE_CURRENT_SOURCE_DIR}/3rdParty/antlr)
include_directories(${ANTLR_PATH}/include)
link_directories(${ANTLR_PATH})
link_libraries(antlr4-runtime)

#generate Parser
execute_process(COMMAND java -jar ${ANTLR_PATH}/antlr-4.9.2-complete.jar -Dlanguage=Cpp -visitor -no-listener -o parser -package tmshell ${CMAKE_CURRENT_SOURCE_DIR}/grammar/TMSlang.g4
WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})   

#for boost
set(Boost_USE_DEBUG_LIBS        OFF)
set(Boost_USE_RELEASE_LIBS       ON)
set(Boost_USE_STATIC_LIBS        ON)
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME    OFF)
set(Boost_USE_DEBUG_RUNTIME     OFF)
set(Boost_COMPILER vc142)
set(Boost_ADDITIONAL_VERSIONS "1.76" "1.76.0" "1.78" "1.78.0" "1.79" "1.79.0")
find_package(Boost 1.36.0 REQUIRED COMPONENTS filesystem system PATHS 3rdParty)
if (NOT Boost_FOUND)
  message(FATAL_ERROR "Fatal error: Boost (version >= 1.55) required.")
endif()

include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})

file(GLOB parser_source CONFIGURE_DEPENDS parser/*.cpp)
file(GLOB tmshell_source CONFIGURE_DEPENDS tmshell/*.cpp)
file(GLOB tmshelld_source CONFIGURE_DEPENDS tmshelld/*.cpp)

add_library(parser
    OBJECT
    ${parser_source}
)

add_executable(
    tmshell

    ${tmshell_source}
    $<TARGET_OBJECTS:parser>
)
target_link_libraries(tmshell ${Boost_LIBRARIES})

add_executable(
    tmshelld

    ${tmshelld_source}
    $<TARGET_OBJECTS:parser>
)
target_link_libraries(tmshelld ${Boost_LIBRARIES})
