/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** AMouseEvent.hpp
*/

#pragma once

#include "shared/graphics/events/IMouseEvent.hpp"

using namespace shared::graphics::events;
using namespace shared::types;

namespace arcade::graphics::common::events {
    template <EventType T>
    class AMouseEvent;
}

template <EventType T>
class arcade::graphics::common::events::AMouseEvent: public IMouseEvent {
public:
    ~AMouseEvent() override = default;

    EventType getType() const noexcept override {
        return T;
    }

    const Vector2i getPosition() const noexcept override {
        return _pos;
    }

protected:
    /**
     * @brief Construct a new AMouseEvent object
     *
     * @param pos Position of the mouse
     */
    explicit AMouseEvent(Vector2i pos): _pos(pos){};

    Vector2i        _pos;
};
