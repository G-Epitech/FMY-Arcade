/*
** EPITECH PROJECT, 2024
** arcade-shared
** File description:
** IPositionComponent
*/

#pragma once

#include "IComponent.hpp"
#include "../../types/Vector.hpp"

namespace shared::games::components {
  class IPositionComponent;
}

class shared::games::components::IPositionComponent: public virtual IComponent
{
  public:
    virtual ~IPositionComponent() = default;

    /**
     * @brief Get position of the entity (tiles)
     *
     */
    virtual types::Vector2i &getPosition(void) noexcept = 0;
};
