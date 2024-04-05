/*
** EPITECH PROJECT, 2024
** MapEntity.cpp
** File description:
** MapEntity class
*/

#include <fstream>
#include "MapEntity.hpp"
#include "common/components/TextureComponent.hpp"
#include "common/components/CollidableComponent.hpp"

using namespace arcade::games::pacman;
using namespace arcade::games::common::components;
using namespace shared::types;

MapEntity::MapEntity(std::string mapFile) {
    this->_generateWalls(mapFile);
}

void MapEntity::_generateWalls(std::string &mapFile) {
    std::ifstream file(mapFile);
    char part = '\0';
    Vector2i position = Vector2i(0, 0);

    if (!file)
        return;
    while (file.get(part)) {
        if (part == '\n') {
            position.x = 0;
            position.y++;
            continue;
        }
        if (part == '#')
            this->_createWall(position);
        if (part == ' ')
            this->_createPoint(position);
        position.x++;
    }
    file.close();
}

void MapEntity::_createWall(shared::types::Vector2i position) {
    shared::games::components::TextureProps textureProps = {
            .sources = {
                    .ascii = "assets/pacman/map.ascii",
                    .bin = "assets/pacman/map.png",
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

void MapEntity::_createPoint(shared::types::Vector2i position) {
    shared::games::components::TextureProps textureProps = {
            .sources = {
                    .ascii = "assets/pacman/point.ascii",
                    .bin = "assets/pacman/point.png",
                    .binTileSize = Vector2f(100, 100)
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
