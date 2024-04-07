/*
** EPITECH PROJECT, 2024
** HeadEntity.cpp
** File description:
** HeadEntity class
*/

#include "SnakeGame.hpp"
#include "HeadEntity.hpp"
#include "../wall/WallEntity.hpp"
#include "components/HeadKeyboardComponent.hpp"

using namespace arcade::games::common::components;
using namespace shared::games::components;

arcade::games::snake::HeadEntity::HeadEntity() : _textureProps(
        arcade::games::snake::HeadEntity::_defaultTextureProps()),
                                                 direction(1, 0),
                                                 position(6, 10) {
    std::shared_ptr<CollidableComponent> collide = std::make_shared<CollidableComponent>(*this, HeadEntity::_onCollide);
    std::shared_ptr<TextureComponent> texture = std::make_shared<TextureComponent>(*this, Vector2u(1, 1), 10,
                                                                                   this->_textureProps);
    std::shared_ptr<components::HeadKeyboardComponent> keyboard = std::make_shared<components::HeadKeyboardComponent>(
            *this);

    this->_components.push_back(collide);
    this->_components.push_back(texture);
    this->_components.push_back(keyboard);
    this->reset();
}

shared::games::components::TextureProps arcade::games::snake::HeadEntity::_defaultTextureProps() {
    return {
            .sources = {
                    .ascii = "assets/snake/head.ascii",
                    .bin = "assets/snake/head.png",
                    .binTileSize = Vector2f(40, 40)
            },
            .origin = Vector2u(3, 0)
    };
}

void arcade::games::snake::HeadEntity::forward() {
    this->position.x += this->direction.x;
    this->position.y += this->direction.y;

    for (auto &component: this->_components) {
        auto posCmp = std::dynamic_pointer_cast<PositionableComponent>(component);
        if (posCmp == nullptr) continue;

        posCmp->getPosition().x += this->direction.x;
        posCmp->getPosition().y += this->direction.y;

        auto textureCmp = std::dynamic_pointer_cast<TextureComponent>(component);
        if (textureCmp == nullptr) continue;

        textureCmp->getTextureProps().origin = Vector2u(0, 0);
        if (this->direction.y == 0)
            textureCmp->getTextureProps().origin.x = 2;
        if (this->direction.x > 0)
            textureCmp->getTextureProps().origin.x += 1;
        if (this->direction.y > 0)
            textureCmp->getTextureProps().origin.x += 1;
    }
}

void arcade::games::snake::HeadEntity::_onCollide(std::shared_ptr<shared::games::IGame> ctx,
                                                  std::shared_ptr<shared::games::components::ICollidableComponent> target) {
    auto game = std::dynamic_pointer_cast<SnakeGame>(ctx);

    if (!game)
        return;
    if (dynamic_cast<const WallEntity *>(&target->getEntity()) || dynamic_cast<const TailEntity *>(&target->getEntity())) {
        game->setLooseGame(true);
    }
}

void arcade::games::snake::HeadEntity::reset() {
    this->direction = Vector2i(1, 0);
    this->position = Vector2i(6, 10);
    for (auto &component: this->_components) {
        std::shared_ptr<PositionableComponent> posCmp = std::dynamic_pointer_cast<PositionableComponent>(component);
        if (posCmp == nullptr) continue;

        posCmp->getPosition().x = this->position.x;
        posCmp->getPosition().y = this->position.y;
    }
}
