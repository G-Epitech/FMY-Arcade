/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** AMouseEvent.hpp
*/

#pragma once

#include "AMouseEvent.hpp"
#include "shared/graphics/events/IMouseButtonEvent.hpp"

using namespace shared::graphics::events;
using namespace shared::types;
using namespace arcade::graphics::common::events;

namespace arcade::graphics::common::events {
    template<EventType T>
    concept MouseButtonEventType = T == EventType::MOUSE_BTN_PRESS || T == EventType::MOUSE_BTN_RELEASE;

    template<EventType T> requires MouseButtonEventType<T>
    class AMouseButtonEvent;
}

template<EventType T> requires MouseButtonEventType<T>
class arcade::graphics::common::events::AMouseButtonEvent: public AMouseEvent<T>, public virtual IMouseButtonEvent {
public:
    /**
     * @brief Construct a new AMouseButtonEvent object
     *
     * @param pos Position of the mouse
     * @param button Targeted button
     */
    explicit AMouseButtonEvent(
        Vector2i pos,
        MouseButton button
    ): AMouseEvent<T>(pos), _button(button) {};

    ~AMouseButtonEvent() override = default;

    /**
     * @brief Get the button object
     *
     * @return Target button type
     */
    const MouseButton getButton() const noexcept override {
        return _button;
    }

protected:
    const MouseButton _button;
};
