/*
** EPITECH PROJECT, 2024
** arcade-shared
** File description:
** IPositionableComponent
*/

#pragma once

#include "IComponent.hpp"
#include "../../types/Vector.hpp"

namespace shared::games::components {
  class IPositionableComponent;
}

class shared::games::components::IPositionableComponent: public virtual IComponent
{
  public:
    virtual ~IPositionableComponent() = default;

    /**
     * @brief Get position of the entity (tiles)
     *
     */
    virtual types::Vector2i &getPosition() noexcept = 0;

    /**
     * @brief Get size of the entity (tiles)
     *
     */
    virtual types::Vector2u &getSize() noexcept = 0;
};
