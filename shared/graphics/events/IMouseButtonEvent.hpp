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

class shared::graphics::events::IMouseButtonEvent : public IMouseEvent {
public:
    virtual ~IMouseButtonEvent() = default;

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
