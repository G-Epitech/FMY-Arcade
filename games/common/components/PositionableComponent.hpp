/*
** EPITECH PROJECT, 2024
** PositionableComponent.hpp
** File description:
** PositionableComponent class
*/

#pragma once

#include "shared/games/components/IPositionableComponent.hpp"
#include "AComponent.hpp"

namespace arcade::games::common::components {
    class PositionableComponent;
}

class arcade::games::common::components::PositionableComponent
        : public AComponent, public virtual shared::games::components::IPositionableComponent {
public:
    ~PositionableComponent() override = default;

    /**
     * @brief Create a position component
     * @param entity
     */
    explicit PositionableComponent(shared::games::entity::IEntity &entity);

    /**
     * @brief Get position of the entity (tiles)
     *
     */
    shared::types::Vector2f &getPosition() noexcept override;

    /**
     * @brief Get size of the entity (tiles)
     *
     */
     shared::types::Vector2u &getSize() noexcept override;

protected:
    shared::types::Vector2f _position;
    shared::types::Vector2u _size;
};
