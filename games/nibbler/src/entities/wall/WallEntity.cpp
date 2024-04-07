/*
** EPITECH PROJECT, 2024
** WallEntity.cpp
** File description:
** WallEntity class
*/

#include <fstream>
#include <iostream>
#include "WallEntity.hpp"
#include "common/components/CollidableComponent.hpp"
#include "common/components/TextureComponent.hpp"

using namespace arcade::games::nibbler;
using namespace arcade::games::common::components;

WallEntity::WallEntity(shared::types::Vector2u size) {
    this->_createWall(Vector2i(size.x, size.y));
}

void WallEntity::_createWall(shared::types::Vector2i position) {
    shared::games::components::TextureProps textureProps = {
            .sources = {
                    .ascii = "assets/nibbler/wall.ascii",
                    .bin = "assets/nibbler/wall.png",
                    .binTileSize = Vector2f(40, 40)
            },
            .origin = Vector2u(0, 0)
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
}

WallEntity::WallException::WallException(const std::string &message) : _message(message) {}

const char *WallEntity::WallException::what() const noexcept {
    return this->_message.c_str();
}
