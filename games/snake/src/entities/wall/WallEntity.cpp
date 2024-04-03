/*
** EPITECH PROJECT, 2024
** WallEntity.cpp
** File description:
** WallEntity class
*/

#include "WallEntity.hpp"
#include "common/components/CollidableComponent.hpp"
#include "common/components/TextureComponent.hpp"

using namespace arcade::games::snake;
using namespace arcade::games::common::components;

WallEntity::WallEntity(shared::types::Vector2u size) {
    if (size.x < 3 || size.y < 3)
        throw WallExeption("Invalid size of map");

    for (std::size_t y = 0; y < size.y; y++) {
        this->_createWall(Vector2i(0, y));
    }
    for (std::size_t x = 1; x < size.x - 1; x++) {
        this->_createWall(Vector2i(x, 0));
        this->_createWall(Vector2i(x, size.y - 1));
    }
    for (std::size_t y = 0; y < size.y; y++) {
        this->_createWall(Vector2i(size.x - 1, y));
    }
}

void WallEntity::_createWall(shared::types::Vector2i position) {
    shared::games::components::TextureProps textureProps = {
            .sources = {
                    .ascii = "assets/snake/wall.ascii",
                    .bin = "assets/snake/wall.png",
                    .binTileSize = Vector2f(40, 40)
            },
            .origin = Vector2u(0, 0)
    };
    std::shared_ptr<CollidableComponent> collision = std::make_shared<CollidableComponent>(*this, nullptr);
    std::shared_ptr<TextureComponent> texture = std::make_shared<TextureComponent>(*this, Vector2u(1, 1), 1,
                                                                                   textureProps);

    collision->getPosition().x = position.x;
    collision->getPosition().y = position.y;
    this->_components.push_back(collision);
    texture->getPosition().x = position.x;
    texture->getPosition().y = position.y;
    this->_components.push_back(texture);
}

WallEntity::WallExeption::WallExeption(const std::string &message) : _message(message) {}

const char *WallEntity::WallExeption::what() const noexcept {
    return this->_message.c_str();
}
