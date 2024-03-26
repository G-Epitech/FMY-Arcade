/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Snake.hpp
*/

#pragma once

#include <map>
#include <vector>
#include <memory>

#include "shared/types/UUId.hpp"
#include "common/game/AGame.hpp"

namespace arcade::games::snake {
    class Snake;
}

class arcade::games::snake::Snake {
public:
    Snake();
    ~Snake();

    /**
     * @brief Entities that compose the snake
     *
     */
    std::vector<common::EntityPtr> body;

    /**
     * @brief Head of the snake
     *
     */
    common::EntityPtr head;
};
