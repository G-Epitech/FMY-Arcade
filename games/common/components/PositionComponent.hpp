/*
** EPITECH PROJECT, 2024
** PositionComponent.hpp
** File description:
** PositionComponent class
*/

#pragma once

#include "shared/games/components/IPositionComponent.hpp"
#include "AComponent.hpp"

namespace arcade::games::common::components {
    class PositionComponent;
}

class arcade::games::common::components::PositionComponent
        : public AComponent, public virtual shared::games::components::IPositionComponent {
public:
    ~PositionComponent() override = default;

    /**
     * @brief Create a position component
     * @param entity
     */
    explicit PositionComponent(shared::games::entity::IEntity &entity);

    /**
     * @brief Get position of the entity (tiles)
     *
     */
    shared::types::Vector2i &getPosition() noexcept override;

protected:
    shared::types::Vector2i _position;
};
