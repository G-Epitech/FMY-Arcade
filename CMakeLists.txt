cmake_minimum_required(VERSION 3.27)
project(arcade)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")

target_include_directories (arcade PUBLIC ${CMAKE_CURRENT_LIST_DIR}/common)
add_subdirectory(src)
