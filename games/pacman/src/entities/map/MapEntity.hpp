/*
** EPITECH PROJECT, 2024
** MapEntity.hpp
** File description:
** MapEntity class
*/

#pragma once

#include "common/entity/AEntity.hpp"
#include "shared/types/Vector.hpp"
#include "PointEntity.hpp"

namespace arcade::games::pacman {
    class MapEntity;
}

class arcade::games::pacman::MapEntity : public common::AEntity {
public:
    ~MapEntity() override = default;
    MapEntity() = default;

    /**
     * Generate all wall of the map
     * @param mapFile Path of the map
     * @return List of points
     */
    std::vector<std::shared_ptr<PointEntity>> generateWalls(std::string mapFile);

    std::vector<std::string> mapData;
protected:
    /**
     * @brief Create a wall (part of) (Component creation)
     * @param position Position of the wall
     */
    void _createWall(shared::types::Vector2i position);
};
