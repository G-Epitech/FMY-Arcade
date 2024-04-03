/*
** EPITECH PROJECT, 2024
** BackgroundEntity.cpp
** File description:
** BackgroundEntity class
*/

#include "BackgroundEntity.hpp"
#include "common/components/TextureComponent.hpp"

using namespace arcade::games::snake;
using namespace arcade::games::common::components;

arcade::games::snake::BackgroundEntity::BackgroundEntity(shared::types::Vector2u size) {
    unsigned int textureOriginX = 1;
    unsigned int textureOriginY = 1;

    for (std::size_t x = 1; x < size.x - 1; x++) {
        for (std::size_t y = 1; y < size.y - 1; y++) {
            this->_addColor(Vector2i(x, y), Vector2u(textureOriginY, 0));
            textureOriginY = textureOriginY == 1 ? 2 : 1;
        }
        textureOriginX = textureOriginX == 1 ? 2 : 1;
        textureOriginY = textureOriginX;
    }
}

void arcade::games::snake::BackgroundEntity::_addColor(shared::types::Vector2i position, shared::types::Vector2u origin) {
    shared::games::components::TextureProps textureProps = {
            .sources = {
                    .ascii = "assets/snake/wall.ascii",
                    .bin = "assets/snake/wall.png",
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
