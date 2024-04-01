/*
** EPITECH PROJECT, 2024
** CollidableComponent.hpp
** File description:
** CollidableComponent class
*/

#pragma once

#include "shared/games/components/ICollidableComponent.hpp"
#include "PositionableComponent.hpp"

namespace arcade::games::common::components {
    class CollidableComponent;
}

class arcade::games::common::components::CollidableComponent : public virtual shared::games::components::ICollidableComponent, public PositionableComponent {
public:
    ~CollidableComponent() override = default;

    /**
     * @brief Create a position component
     * @param entity
     */
    explicit CollidableComponent(shared::games::entity::IEntity &entity);

    /**
     * @brief On collide event handler for the component
     * @param ctx Context of the game
     * @param target Target entity
     */
    void onCollide(std::shared_ptr<shared::games::IGame> &ctx, std::shared_ptr<ICollidableComponent> target) override;
};
