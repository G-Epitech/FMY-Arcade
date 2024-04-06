/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** NibblerGame.hpp
*/

#pragma once

#include "common/game/AGame.hpp"
#include "games/nibbler/src/entities/nibbler/Nibbler.hpp"
#include "entities/apple/AppleEntity.hpp"
#include "common/components/SoundComponent.hpp"

namespace arcade::games::nibbler {
    class NibblerGame;
}

class arcade::games::nibbler::NibblerGame : public arcade::games::common::AGame {
public:
    NibblerGame();

    ~NibblerGame() override = default;

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

    /**
     * @brief Add new point to player and re-generate an apple
     */
    void addNewPoint();

    /**
     * @brief Change the state of a sound
     * 
     * @param soundName Name of the sound
     * @param state State of the sound
     */
    void changeStateSound(const std::string &soundName, shared::games::components::SoundState state);

    /**
     * @brief Change to a specific level
     */
    void changeToLevel(int level);

    /**
     * @brief Check if the direction is valid
     * 
     * @param direction 
     * @return true
     * @return false
     */
    bool isValidDirection(Vector2i direction);

    unsigned int speedTime;

    unsigned int speedBoost;

    bool moved;

    bool canMakeChoice;

protected:
    /**
     * @brief Execute the process of the end of the game when the player _loose
     */
    void _loose();

    /**
     * @brief Prevent wall collision
     */
    void _preventWallCollision();

    typedef enum {
        WALL,
        SPACE,
    } CellType;

    std::unique_ptr<Nibbler> _nibbler;
    std::shared_ptr<AppleEntity> _apple;
    shared::games::DeltaTime _clock;
    std::map<int, std::map<int, CellType>> _map;
    bool _looseGame;
    int _currentScore;
};
