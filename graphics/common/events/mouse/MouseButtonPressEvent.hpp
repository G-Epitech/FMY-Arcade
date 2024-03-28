/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** MouseButtonPressEvent.hpp
*/

#pragma once

#include "AMouseButtonEvent.hpp"

using namespace shared::graphics::events;
using namespace arcade::graphics::common::events;

namespace arcade::graphics::common::events {
    class MouseButtonPressEvent;
};

class arcade::graphics::common::events::MouseButtonPressEvent :
    public AMouseButtonEvent<EventType::MOUSE_BTN_PRESS> {
public:
    MouseButtonPressEvent(Vector2i pos, MouseButton button) : AMouseButtonEvent(pos, button){};
    ~MouseButtonPressEvent() override = default;
};
