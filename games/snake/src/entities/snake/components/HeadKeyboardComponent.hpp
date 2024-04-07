/*
** EPITECH PROJECT, 2024
** HeadKeyboardComponent.hpp
** File description:
** HeadKeyboardComponent class
*/

#pragma once

#include <map>
#include "shared/games/components/IKeyboardComponent.hpp"
#include "common/components/AComponent.hpp"
#include "../HeadEntity.hpp"

#include "common/components/SoundComponent.hpp"

namespace arcade::games::snake::components {
    class HeadKeyboardComponent;
}

class arcade::games::snake::components::HeadKeyboardComponent
        : public common::components::AComponent, public virtual shared::games::components::IKeyboardComponent {
public:
    ~HeadKeyboardComponent() override = default;

    /**
     * @brief Create a keyboard component
     * @param entity
     */
    explicit HeadKeyboardComponent(HeadEntity &entity);

    /**
     * @brief On key pressed event handler for the entity
     * @param ctx Context of the game
     * @param keyData Key data of key pressed
     */
    void onKeyPress(std::shared_ptr<shared::games::IGame> ctx, shared::games::components::IKeyboardComponent::KeyData keyData) override;

    /**
     * @brief On key release event handler for the entity
     * @param ctx Context of the game
     * @param keyData Key data of key released
     */
    void onKeyRelease(std::shared_ptr<shared::games::IGame> ctx, shared::games::components::IKeyboardComponent::KeyData keyData) override;

    /**
     * @brief Map of sounds
     * 
     */
    std::map<std::string, std::shared_ptr<arcade::games::common::components::SoundComponent>> sounds;
protected:
    HeadEntity &_parent;
    Vector2i _previousDirection;

    void _playSound(const std::string &soundName);

    /**
     * @brief On sound state change event UP
     * 
     * @param ctx Game context
     * @param state new state of the sound
     */
    static void _onSoundStateChangeUp(std::shared_ptr<shared::games::IGame> ctx, shared::games::components::SoundState state);

    /**
     * @brief On sound state change event DOWN
     * 
     * @param ctx Game context
     * @param state new state of the sound
     */
    static void _onSoundStateChangeDown(std::shared_ptr<shared::games::IGame> ctx, shared::games::components::SoundState state);

    /**
     * @brief On sound state change event LEFT
     * 
     * @param ctx Game context
     * @param state new state of the sound
     */
    static void _onSoundStateChangeLeft(std::shared_ptr<shared::games::IGame> ctx, shared::games::components::SoundState state);

    /**
     * @brief On sound state change event RIGHT
     * 
     * @param ctx Game context
     * @param state new state of the sound
     */
    static void _onSoundStateChangeRight(std::shared_ptr<shared::games::IGame> ctx, shared::games::components::SoundState state);

    /**
     * @brief On sound state change event EAT
     * 
     * @param ctx Game context
     * @param state new state of the sound
     */
    static void _onSoundStateChangeEat(std::shared_ptr<shared::games::IGame> ctx, shared::games::components::SoundState state);

    /**
     * @brief On sound state change event DEATH
     * 
     * @param ctx Game context
     * @param state new state of the sound
     */
    static void _onSoundStateChangeDeath(std::shared_ptr<shared::games::IGame> ctx, shared::games::components::SoundState state);
};
