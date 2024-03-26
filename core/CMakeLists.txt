project(arcade)
add_executable(${PROJECT_NAME}    
  main.cpp
)

target_compile_options(${PROJECT_NAME} PUBLIC -fno-gnu-unique)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR}/..)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR}/src)

add_subdirectory(src)
