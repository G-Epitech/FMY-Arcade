/*
** EPITECH PROJECT, 2024
** PointEntity.cpp
** File description:
** PointEntity class
*/

#include "PointEntity.hpp"
#include "common/components/TextureComponent.hpp"
#include "common/components/CollidableComponent.hpp"

using namespace arcade::games::pacman;
using namespace arcade::games::common::components;
using namespace shared::types;

arcade::games::pacman::PointEntity::PointEntity(shared::types::Vector2i position, bool ghostBonus): position(0, 0) {
    this->_ghostBonus = ghostBonus;
    this->_spawn(position);
}

void PointEntity::_spawn(shared::types::Vector2i position) {
    shared::games::components::TextureProps textureProps = {
            .sources = {
                    .ascii = "assets/pacman/point.ascii",
                    .bin = "assets/pacman/point.png",
                    .binTileSize = Vector2f(100, 100)
            },
            .origin = Vector2u(this->_ghostBonus ? 1 : 0, 0)
    };
    std::shared_ptr<CollidableComponent> collision = std::make_shared<CollidableComponent>(*this, nullptr);
    std::shared_ptr<TextureComponent> texture = std::make_shared<TextureComponent>(*this, Vector2u(1, 1), 11,
                                                                                   textureProps);

    collision->getPosition().x = position.x;
    collision->getPosition().y = position.y;
    this->_components.push_back(collision);
    texture->getPosition().x = position.x;
    texture->getPosition().y = position.y;
    this->_components.push_back(texture);

    this->position = position;
}
