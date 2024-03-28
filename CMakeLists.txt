cmake_minimum_required(VERSION 3.27)
project(arcade)

set(ARCADE_BIN_DIR ${CMAKE_CURRENT_LIST_DIR})
set(ARCADE_LIB_DIR ${CMAKE_CURRENT_LIST_DIR}/lib)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${ARCADE_BIN_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${ARCADE_LIB_DIR})
set(CMAKE_SHARED_LIBRARY_PREFIX "arcade_")

add_subdirectory(core)
add_subdirectory(games)
add_subdirectory(graphics)
