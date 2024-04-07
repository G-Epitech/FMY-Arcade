/*
** EPITECH PROJECT, 2024
** arcade-shared
** File description:
** ICollidableComponent
*/

#pragma once

#include "../IGame.hpp"
#include "IPositionableComponent.hpp"
#include "../../types/Vector.hpp"

namespace shared::games::components {
    class ICollidableComponent;
}

/**
 * @brief Interface of a collidable component
 * 
 */
class shared::games::components::ICollidableComponent: public virtual IPositionableComponent {
public:
    virtual ~ICollidableComponent() = default;

    /**
     * @brief On collide event handler for the component
     * @param ctx Context of the game
     * @param target Target entity
     */
    virtual void onCollide(std::shared_ptr<IGame> ctx, std::shared_ptr<ICollidableComponent> target) = 0;
};
