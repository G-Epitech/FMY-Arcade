/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** KeyPressEvent.hpp
*/

#pragma once

#include "AKeyEvent.hpp"

namespace arcade::graphics::common::events {
    class KeyPressEvent;
}

class arcade::graphics::common::events::KeyPressEvent: public AKeyEvent<EventType::KEY_PRESS> {
public:
    using AKeyEvent::AKeyEvent;
};
