/*
** EPITECH PROJECT, 2024
** MapEntity.hpp
** File description:
** MapEntity class
*/

#pragma once

#include "common/entity/AEntity.hpp"
#include "shared/types/Vector.hpp"

namespace arcade::games::pacman {
    class MapEntity;
}

class arcade::games::pacman::MapEntity : public common::AEntity {
public:
    ~MapEntity() override = default;

    /**
     * @brief Create a map
     * @param mapFile Path of the map
     */
    explicit MapEntity(std::string mapFile);

protected:
    /**
     * Generate all wall of the map
     * @param mapFile Path of the map
     */
    void _generateWalls(std::string &mapFile);

    /**
     * @brief Create a wall (part of) (Component creation)
     * @param position Position of the wall
     */
    void _createWall(shared::types::Vector2i position);

    /**
     * @brief Create a point on the map
     * @param position Position of the point
     */
    void _createPoint(shared::types::Vector2i position);
};
