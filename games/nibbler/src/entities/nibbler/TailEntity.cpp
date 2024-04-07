/*
** EPITECH PROJECT, 2024
** TailEntity.cpp
** File description:
** TailEntity class
*/

#include "TailEntity.hpp"

using namespace arcade::games::common::components;
using namespace shared::games::components;

arcade::games::nibbler::TailEntity::TailEntity() : _textureProps(
        arcade::games::nibbler::TailEntity::_defaultTextureProps()), _position(0, 0) {
    std::shared_ptr<CollidableComponent> collide = std::make_shared<CollidableComponent>(*this, nullptr);
    std::shared_ptr<TextureComponent> texture = std::make_shared<TextureComponent>(*this, Vector2u(1, 1), 10,
                                                                                   this->_textureProps);
    this->_components.push_back(collide);
    this->_components.push_back(texture);
}

shared::games::components::TextureProps arcade::games::nibbler::TailEntity::_defaultTextureProps() {
    return {
            .sources = {
                    .ascii = "assets/nibbler/tail.ascii",
                    .bin = "assets/nibbler/tail.png",
                    .binTileSize = Vector2f(40, 40)
            },
            .origin = Vector2u(0, 0)
    };
}

void arcade::games::nibbler::TailEntity::setPosition(Vector2i position) {
    this->_position = position;

    for (auto &component: this->_components) {
        auto posCmp = std::dynamic_pointer_cast<PositionableComponent>(component);
        if (posCmp == nullptr) continue;

        posCmp->getPosition().x = position.x;
        posCmp->getPosition().y = position.y;
    }
}

void arcade::games::nibbler::TailEntity::setTextureOrigin(shared::types::Vector2u origin) {
    for (auto &component: this->_components) {
        auto txCmp = std::dynamic_pointer_cast<TextureComponent>(component);
        if (txCmp == nullptr) continue;

        txCmp->getTextureProps().origin = origin;
    }
}

Vector2i arcade::games::nibbler::TailEntity::getPosition() {
    return this->_position;
}
