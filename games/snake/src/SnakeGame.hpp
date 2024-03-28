/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** SnakeGame.hpp
*/

#pragma once

#include "common/game/AGame.hpp"
#include "games/snake/src/entities/snake/Snake.hpp"

namespace arcade::games::snake {
    class SnakeGame;
}

class arcade::games::snake::SnakeGame : public arcade::games::common::AGame {
public:
    SnakeGame();

    ~SnakeGame() override;

    /**
     * @brief Game manifest
     *
     */
    static const shared::games::GameManifest manifest;

    /**
     * @brief Get the manifest object
     *
     * @return const shared::games::GameManifest&
     */
    const shared::games::GameManifest &getManifest() const noexcept override;

    /**
     * @brief Allow game possible actions
     *
     * @param dt Delta time from last frame
     */
    void compute(shared::games::DeltaTime dt) override;

protected:
    std::unique_ptr<Snake> _snake;
};
