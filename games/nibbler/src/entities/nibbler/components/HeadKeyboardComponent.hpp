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

namespace arcade::games::nibbler::components {
    class HeadKeyboardComponent;
}

class arcade::games::nibbler::components::HeadKeyboardComponent
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

protected:
    HeadEntity &_parent;
    Vector2i _previousDirection;

};
