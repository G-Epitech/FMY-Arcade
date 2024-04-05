project(pacman)
add_library(${PROJECT_NAME} SHARED
        export.cpp
        src/PacmanGame.cpp
        src/PacmanGame.hpp
        src/PacmanGameProvider.cpp
        src/PacmanGameProvider.hpp
)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/../common PRIVATE)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR}/src)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR}/../..)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR}/..)
