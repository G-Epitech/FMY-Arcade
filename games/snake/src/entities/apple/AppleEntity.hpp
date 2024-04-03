/*
** EPITECH PROJECT, 2024
** AppleEntity.hpp
** File description:
** AppleEntity class
*/

#pragma once

#include "common/entity/AEntity.hpp"
#include "shared/types/Vector.hpp"

namespace arcade::games::snake {
    class AppleEntity;
}

class arcade::games::snake::AppleEntity : public common::AEntity {
public:
    ~AppleEntity() override = default;

    /**
     * @brief Create the apple entity
     * @param size Size of the map
     */
    explicit AppleEntity(shared::types::Vector2u
    size);

    /**
     * @brief Update the position of the apple on the map
     * (As a new apple reward for the player)
     */
    void generateApple();

protected:
    /**
     * @brief Create the apple components
     */
    void _create();

    shared::types::Vector2u _mapSize;
};
