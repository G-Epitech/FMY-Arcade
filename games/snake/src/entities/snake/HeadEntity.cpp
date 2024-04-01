/*
** EPITECH PROJECT, 2024
** HeadEntity.cpp
** File description:
** HeadEntity class
*/

#include "HeadEntity.hpp"
#include "components/HeadKeyboardComponent.hpp"

using namespace arcade::games::common::components;
using namespace shared::games::components;

arcade::games::snake::HeadEntity::HeadEntity() : _textureProps(
        arcade::games::snake::HeadEntity::_defaultTextureProps()),
                                                 direction(1, 0) {
    std::shared_ptr<CollidableComponent> collide = std::make_shared<CollidableComponent>(*this);
    std::shared_ptr<TextureComponent> texture = std::make_shared<TextureComponent>(*this, Vector2u(1, 1), 10,
                                                                                   this->_textureProps);
    std::shared_ptr<components::HeadKeyboardComponent> keyboard = std::make_shared<components::HeadKeyboardComponent>(
            *this);

    collide->getPosition().x = 8;
    collide->getPosition().y = 4;
    this->_components.push_back(collide);

    texture->getPosition().x = 8;
    texture->getPosition().y = 4;
    this->_components.push_back(texture);

    this->_components.push_back(keyboard);
}

shared::games::components::TextureProps arcade::games::snake::HeadEntity::_defaultTextureProps() {
    return {
            .sources = {
                    .ascii = "assets/snake/head.ascii",
                    .bin = "assets/snake/head.png",
                    .binTileSize = Vector2f(40, 40)
            },
            .origin = Vector2u(0, 0)
    };
}

void arcade::games::snake::HeadEntity::forward() {
    for (auto &component: this->_components) {
        std::shared_ptr<PositionableComponent> posCmp = std::dynamic_pointer_cast<PositionableComponent>(component);
        if (posCmp == nullptr) continue;

        posCmp->getPosition().x += this->direction.x;
        posCmp->getPosition().y += this->direction.y;
    }
}
