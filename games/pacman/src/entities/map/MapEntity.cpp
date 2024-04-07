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

std::vector<std::shared_ptr<PointEntity>> MapEntity::generateWalls(std::string mapFile) {
    std::vector<std::shared_ptr<PointEntity>> list;
    std::vector<std::string> map;

    std::ifstream file(mapFile);
    char part = '\0';
    Vector2i position = Vector2i(0, 0);

    if (!file)
        return list;
    map.push_back("");
    while (file.get(part)) {
        if (part == '\n') {
            map.push_back("");
            position.x = 0;
            position.y++;
            continue;
        }
        map[position.y].push_back(part);
        if (part == '#')
            this->_createWall(position);
        if (part == ' ') {
            list.push_back(std::make_shared<PointEntity>(position, false));
        }
        if (part == '?') {
            list.push_back(std::make_shared<PointEntity>(position, true));
        }
        position.x++;
    }
    file.close();
    this->mapData = map;
    return list;
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
    std::shared_ptr<TextureComponent> texture = std::make_shared<TextureComponent>(*this, Vector2u(1, 1), 1,
                                                                                   textureProps);

    collision->getPosition().x = position.x;
    collision->getPosition().y = position.y;
    this->_components.push_back(collision);
    texture->getPosition().x = position.x;
    texture->getPosition().y = position.y;
    this->_components.push_back(texture);
}
