add_executable(arcade
  main.cpp
)

target_include_directories(arcade PUBLIC ${CMAKE_CURRENT_LIST_DIR}/..)
target_include_directories(arcade PUBLIC ${CMAKE_CURRENT_LIST_DIR}/src)

add_subdirectory(src)
