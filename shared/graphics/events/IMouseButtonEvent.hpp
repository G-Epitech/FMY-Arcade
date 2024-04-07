/*
** EPITECH PROJECT, 2024
** arcade-shared
** File description:
** IMouseEvent
*/

#pragma once

#include "IMouseEvent.hpp"

namespace shared::graphics::events{
    class IMouseButtonEvent;
}

/**
 * @brief Interface for the mouse button event object
 * 
 */
class shared::graphics::events::IMouseButtonEvent : public virtual IMouseEvent {
public:
    virtual ~IMouseButtonEvent() = default;

    /// @brief Mouse button
    typedef enum {
        LEFT,
        RIGHT
    } MouseButton;

    /**
     * @brief Mouse button released
     *
     * @return Button released or pressed
     */
    virtual const MouseButton getButton(void) const noexcept = 0;
};
