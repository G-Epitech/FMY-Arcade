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

#include "common/game/AGame.hpp"

namespace arcade::games::snake {
    class Snake;
}

class arcade::games::snake::Snake {
public:
    explicit Snake(unsigned int tails);
    ~Snake();

    /**
     * @brief Head of the snake
     *
     */
    shared::games::entity::EntityPtr head;

    /**
     * @brief Add a tail to the snake body
     *
     * @return The entity to the new tail
     */
    shared::games::entity::EntityPtr addTail();

    /**
     * Get tails of the snake
     *
     * @return Vector of tails
     */
    std::vector<shared::games::entity::EntityPtr> &getTails();
protected:
    /**
     * @brief Entities that compose the snake
     *
     */
    std::vector<shared::games::entity::EntityPtr> _tails;
};
