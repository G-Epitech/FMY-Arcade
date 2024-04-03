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
    class MouseButtonReleaseEvent;
};

class arcade::graphics::common::events::MouseButtonReleaseEvent :
    public AMouseButtonEvent<EventType::MOUSE_BTN_RELEASE> {
public:
    using AMouseButtonEvent::AMouseButtonEvent;
};
