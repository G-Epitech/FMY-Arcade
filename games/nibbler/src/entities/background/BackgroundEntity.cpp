/*
** EPITECH PROJECT, 2024
** BackgroundEntity.cpp
** File description:
** BackgroundEntity class
*/

#include <fstream>
#include <iostream>
#include "BackgroundEntity.hpp"
#include "common/components/TextureComponent.hpp"

using namespace arcade::games::nibbler;
using namespace arcade::games::common::components;

arcade::games::nibbler::BackgroundEntity::BackgroundEntity(shared::types::Vector2u size) {
    if (static_cast<int>(size.x + size.y) % 2 == 0)
        this->_addColor(Vector2i(size.x, size.y), Vector2u(1, 0));
    else
        this->_addColor(Vector2i(size.x, size.y), Vector2u(2, 0));
}

void arcade::games::nibbler::BackgroundEntity::_addColor(shared::types::Vector2i position, shared::types::Vector2u origin) {
    shared::games::components::TextureProps textureProps = {
            .sources = {
                    .ascii = "assets/nibbler/wall.ascii",
                    .bin = "assets/nibbler/wall.png",
                    .binTileSize = Vector2f(40, 40)
            },
            .origin = origin
    };
    std::shared_ptr<TextureComponent> texture = std::make_shared<TextureComponent>(*this, Vector2u(1, 1), 2,
                                                                                   textureProps);

    texture->getPosition().x = position.x;
    texture->getPosition().y = position.y;
    this->_components.push_back(texture);
}
