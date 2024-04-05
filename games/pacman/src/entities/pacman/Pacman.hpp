/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** pacman.hpp
*/

#pragma once

#include <map>
#include <vector>
#include <memory>

#include "common/game/AGame.hpp"
#include "shared/games/IEntity.hpp"
#include "HeadEntity.hpp"
#include "TailEntity.hpp"

namespace arcade::games::pacman {
    class Pacman;
}

class arcade::games::pacman::Pacman {
public:
    explicit Pacman(unsigned int tails);
    ~Pacman();

    /**
     * @brief Head of the pacman
     *
     */
    std::shared_ptr<HeadEntity> head;

    /**
     * @brief Add a tail to the pacman body
     *
     * @return The entity to the new tail
     */
    std::shared_ptr<TailEntity>  addTail();

    /**
     * Get tails of the pacman
     *
     * @return Vector of tails
     */
    std::vector<std::shared_ptr<TailEntity>> &getTails();

    /**
     * @brief Reset the pacman
     */
    void reset();

    /**
     * @brief Update the position of the pacman
     */
    void forward();

    shared::games::DeltaTime lastMove;
protected:
    /**
     * @brief Entities that compose the pacman
     *
     */
    std::vector<std::shared_ptr<TailEntity>> _tails;

    unsigned int _baseTails;
};
