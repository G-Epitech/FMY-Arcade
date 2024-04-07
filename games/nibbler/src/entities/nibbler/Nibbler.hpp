/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** nibbler.hpp
*/

#pragma once

#include <map>
#include <vector>
#include <memory>

#include "common/game/AGame.hpp"
#include "shared/games/IEntity.hpp"
#include "HeadEntity.hpp"
#include "TailEntity.hpp"

namespace arcade::games::nibbler {
    class Nibbler;
}

class arcade::games::nibbler::Nibbler {
public:
    explicit Nibbler(unsigned int tails);
    ~Nibbler();

    /**
     * @brief Head of the nibbler
     *
     */
    std::shared_ptr<HeadEntity> head;

    /**
     * @brief Add a tail to the nibbler body
     *
     * @return The entity to the new tail
     */
    std::shared_ptr<TailEntity>  addTail();

    /**
     * Get tails of the nibbler
     *
     * @return Vector of tails
     */
    std::vector<std::shared_ptr<TailEntity>> &getTails();

    /**
     * @brief Reset the nibbler
     */
    void reset();

    /**
     * @brief Update the position of the nibbler
     */
    void forward();

    shared::games::DeltaTime lastMove;
protected:
    /**
     * @brief Entities that compose the nibbler
     *
     */
    std::vector<std::shared_ptr<TailEntity>> _tails;

    unsigned int _baseTails;
};
