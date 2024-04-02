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

    ~SnakeGame() override = default;

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

    /**
     * @brief Set loose game state
     *
     * @param state If the game is loose or not
     */
    void setLooseGame(bool state);

protected:
    /**
     * @brief Execute the process of the end of the game when the player _loose
     */
    void _loose();

    std::unique_ptr<Snake> _snake;
    shared::games::DeltaTime _clock;
    bool _looseGame;
};
