/*
** EPITECH PROJECT, 2024
** TailEntity.cpp
** File description:
** TailEntity class
*/

#include "TailEntity.hpp"

using namespace arcade::games::common::components;
using namespace shared::games::components;

arcade::games::snake::TailEntity::TailEntity() : _textureProps(
        arcade::games::snake::TailEntity::_defaultTextureProps()) {
    std::shared_ptr<CollidableComponent> collide = std::make_shared<CollidableComponent>(*this, nullptr);
    std::shared_ptr<TextureComponent> texture = std::make_shared<TextureComponent>(*this, Vector2u(1, 1), 10,
                                                                                   this->_textureProps);
    this->_components.push_back(collide);
    this->_components.push_back(texture);
}

shared::games::components::TextureProps arcade::games::snake::TailEntity::_defaultTextureProps() {
    return {
            .sources = {
                    .ascii = "assets/snake/tail.ascii",
                    .bin = "assets/snake/tail.png",
                    .binTileSize = Vector2f(40, 40)
            },
            .origin = Vector2u(0, 0)
    };
}
