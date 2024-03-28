/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** AMouseEvent.hpp
*/

#pragma once

#include "AMouseEvent.hpp"

using namespace shared::graphics::events;
using namespace shared::types;

namespace arcade::graphics::common::events {
    class MouseMoveEvent;
}

class arcade::graphics::common::events::MouseMoveEvent: public AMouseEvent<EventType::MOUSE_MOVE> {
public:
    explicit MouseMoveEvent(const Vector2i pos): AMouseEvent<EventType::MOUSE_MOVE>(pos) {}

    ~MouseMoveEvent() override = default;
};
