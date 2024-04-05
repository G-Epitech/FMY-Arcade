project(pacman)
add_library(${PROJECT_NAME} SHARED
        export.cpp
        src/PacmanGameProvider.cpp
        src/PacmanGame.cpp
        src/entities/pacman/Pacman.cpp
        src/entities/pacman/Pacman.hpp
        src/entities/pacman/TailEntity.cpp
        src/entities/pacman/TailEntity.hpp
        src/entities/pacman/HeadEntity.cpp
        src/entities/pacman/HeadEntity.hpp
        src/entities/pacman/components/HeadKeyboardComponent.cpp
        src/entities/pacman/components/HeadKeyboardComponent.hpp
        src/entities/wall/WallEntity.cpp
        src/entities/wall/WallEntity.hpp
        src/entities/background/BackgroundEntity.cpp
        src/entities/background/BackgroundEntity.hpp
        src/entities/apple/AppleEntity.cpp
        src/entities/apple/AppleEntity.hpp
)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/../common PRIVATE)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR}/src)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR}/../..)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR}/..)
