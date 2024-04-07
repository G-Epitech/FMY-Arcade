/*
** EPITECH PROJECT, 2024
** PointEntity.hpp
** File description:
** PointEntity class
*/

#pragma once

#include "common/entity/AEntity.hpp"
#include "shared/types/Vector.hpp"

namespace arcade::games::pacman {
    class PointEntity;
}

class arcade::games::pacman::PointEntity : public common::AEntity {
public:
    ~PointEntity() override = default;

    /**
     * @brief Create a point
     * @param position Position
     * @param ghostBonus If the point is a bonus that let the player eat ghost
     */
    explicit PointEntity(shared::types::Vector2i position, bool ghostBonus);

    shared::types::Vector2i position;

    bool ghostBonus;
protected:
    /**
     * @brief Spawn the point on the map
     * @param position
     */
    void _spawn(shared::types::Vector2i position);
};
