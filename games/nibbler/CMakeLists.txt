project(nibbler)
add_library(${PROJECT_NAME} SHARED
        export.cpp
        src/NibblerGameProvider.cpp
        src/NibblerGame.cpp
        src/entities/nibbler/Nibbler.cpp
        src/entities/nibbler/Nibbler.hpp
        src/entities/nibbler/TailEntity.cpp
        src/entities/nibbler/TailEntity.hpp
        src/entities/nibbler/HeadEntity.cpp
        src/entities/nibbler/HeadEntity.hpp
        src/entities/nibbler/components/HeadKeyboardComponent.cpp
        src/entities/nibbler/components/HeadKeyboardComponent.hpp
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
