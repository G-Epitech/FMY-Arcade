/*
** EPITECH PROJECT, 2024
** AppleEntity.cpp
** File description:
** AppleEntity class
*/

#include <random>
#include "AppleEntity.hpp"
#include "common/components/CollidableComponent.hpp"
#include "common/components/TextureComponent.hpp"

using namespace arcade::games::snake;
using namespace arcade::games::common::components;

arcade::games::snake::AppleEntity::AppleEntity(shared::types::Vector2u size): _mapSize(size) {
    this->_create();
    this->generateApple();
}

void AppleEntity::generateApple() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(1, this->_mapSize.x - 2);
    Vector2i randomPosition = Vector2i(dis(gen), dis(gen));

    for (auto &component: this->_components) {
        auto posCmp = std::dynamic_pointer_cast<PositionableComponent>(component);
        if (posCmp == nullptr) continue;

        posCmp->getPosition().x = randomPosition.x;
        posCmp->getPosition().y = randomPosition.y;
    }
}

void AppleEntity::_create() {
    shared::games::components::TextureProps textureProps = {
            .sources = {
                    .ascii = "assets/snake/apple.ascii",
                    .bin = "assets/snake/apple.png",
                    .binTileSize = Vector2f(40, 40)
            },
            .origin = Vector2u(0, 0)
    };
    std::shared_ptr<CollidableComponent> collision = std::make_shared<CollidableComponent>(*this, nullptr);
    std::shared_ptr<TextureComponent> texture = std::make_shared<TextureComponent>(*this, Vector2u(1, 1), 9,
                                                                                   textureProps);

    this->_components.push_back(collision);
    this->_components.push_back(texture);
}
