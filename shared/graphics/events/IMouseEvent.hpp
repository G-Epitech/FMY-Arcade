/*
** EPITECH PROJECT, 2024
** arcade-shared
** File description:
** IMouseEvent
*/

#pragma once

#include "../../types/Vector.hpp"
#include "IEvent.hpp"

namespace shared::graphics::events {
    class IMouseEvent;
}

/**
 * @brief Interface for the mouse event object
 * 
 */
class shared::graphics::events::IMouseEvent : public virtual IEvent {
public:
    virtual ~IMouseEvent() = default;

    /**
     * @brief Mouse position
     *
     * @return Position of the mouse
     */
    virtual const shared::types::Vector2f getPosition(void) const noexcept = 0;
};
