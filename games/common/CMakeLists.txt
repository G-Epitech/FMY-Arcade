target_sources(${PROJECT_NAME} PUBLIC
        game/AGame.cpp
        game/AGame.hpp
        entity/AEntity.cpp
        entity/AEntity.hpp
        components/AComponent.cpp
        components/AComponent.hpp
        components/PositionComponent.cpp
        components/PositionComponent.hpp
        components/ADisplayableComponent.cpp
        components/ADisplayableComponent.hpp
        components/CollidableComponent.hpp
        components/CollidableComponent.cpp
        components/TextureComponent.hpp
        components/TextureComponent.cpp
)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR}/../..)
