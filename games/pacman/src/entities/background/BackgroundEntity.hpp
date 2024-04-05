/*
** EPITECH PROJECT, 2024
** WallEntity.hpp
** File description:
** WallEntity class
*/

#pragma once

#include <string>
#include "common/entity/AEntity.hpp"
#include "shared/types/Vector.hpp"

namespace arcade::games::pacman {
    class BackgroundEntity;
}

class arcade::games::pacman::BackgroundEntity : public common::AEntity {
public:
    ~BackgroundEntity() override = default;

    /**
     * @brief Create a background to the game
     * @param size Size of the game
     */
    explicit BackgroundEntity(shared::types::Vector2u size);

protected:
    /**
     * @brief Add a color to the background (create a texture composent)
     * @param position Position of the wall
     * @param origin Origin of the texture
     */
    void _addColor(shared::types::Vector2i position, shared::types::Vector2u origin);
};
