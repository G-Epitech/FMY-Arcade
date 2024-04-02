project(snake)
add_library(${PROJECT_NAME} SHARED
        export.cpp
        src/SnakeGameProvider.cpp
        src/SnakeGame.cpp
        src/entities/snake/Snake.cpp
        src/entities/snake/Snake.hpp
        src/entities/snake/TailEntity.cpp
        src/entities/snake/TailEntity.hpp
        src/entities/snake/HeadEntity.cpp
        src/entities/snake/HeadEntity.hpp
        src/entities/snake/components/HeadKeyboardComponent.cpp
        src/entities/snake/components/HeadKeyboardComponent.hpp
        src/entities/wall/WallEntity.cpp
        src/entities/wall/WallEntity.hpp
)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/../common PRIVATE)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR}/src)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR}/../..)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR}/..)
