
cmake_minimum_required(VERSION 3.0)
project(CPP_TP1_JAK_NAT)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

file(MAKE_DIRECTORY output) # Create directory for outputs

set(sources
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Lexique.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/LexiqueLine.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/utilitaire.cpp
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

add_compile_definitions(PROJECT_PATH="${CMAKE_CURRENT_SOURCE_DIR}")

add_executable(CPP_TP1_JAK_NAT ${sources})