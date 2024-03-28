/*
** EPITECH PROJECT, 2024
** TailEntity.cpp
** File description:
** TailEntity class
*/

#include <iostream>
#include "TailEntity.hpp"
#include "common/components/CollidableComponent.hpp"
#include "common/components/TextureComponent.hpp"
#include "shared/games/components/ITextureComponent.hpp"

using namespace arcade::games::common::components;
using namespace shared::games::components;

arcade::games::snake::TailEntity::TailEntity() {
    TextureProps tailTextureProps = {
            .sources = {
                    .ascii = "assets/snake/snake.ascii",
                    .bin = "assets/snake/snake.png",
                    .binTileSize = Vector2f(40, 40)
            },
            .origin = Vector2u(0, 0)
    };

    std::shared_ptr<CollidableComponent> collide = std::make_shared<CollidableComponent>(*this);
    std::shared_ptr<TextureComponent> texture = std::make_shared<TextureComponent>(*this, Vector2u(1, 1), 10,
                                                                                   tailTextureProps);

    this->_components.push_back(collide);
    this->_components.push_back(texture);
}
