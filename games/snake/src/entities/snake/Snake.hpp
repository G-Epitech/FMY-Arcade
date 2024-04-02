/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** snake.hpp
*/

#pragma once

#include <map>
#include <vector>
#include <memory>

#include "common/game/AGame.hpp"
#include "shared/games/IEntity.hpp"
#include "HeadEntity.hpp"
#include "TailEntity.hpp"

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
    std::shared_ptr<HeadEntity> head;

    /**
     * @brief Add a tail to the snake body
     *
     * @return The entity to the new tail
     */
    std::shared_ptr<TailEntity>  addTail();

    /**
     * Get tails of the snake
     *
     * @return Vector of tails
     */
    std::vector<std::shared_ptr<TailEntity>> &getTails();

    /**
     * @brief Reset the snake
     */
    void reset();

    shared::games::DeltaTime lastMove;
protected:
    /**
     * @brief Entities that compose the snake
     *
     */
    std::vector<std::shared_ptr<TailEntity>> _tails;
};
