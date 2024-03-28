target_sources(${PROJECT_NAME} PUBLIC
        game/AGame.cpp
        game/AGame.hpp
        entity/AEntity.cpp
        entity/AEntity.hpp
)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR}/../..)
