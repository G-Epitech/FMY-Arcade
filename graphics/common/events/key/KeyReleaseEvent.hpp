/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** KeyPressEvent.hpp
*/

#pragma once

#include "AKeyEvent.hpp"

namespace arcade::graphics::common::events {
    class KeyReleaseEvent;
}

class arcade::graphics::common::events::KeyReleaseEvent: public AKeyEvent<EventType::KEY_RELEASE> {
public:
    KeyReleaseEvent(const KeyType type, const KeyCode code) : AKeyEvent(type, code) {};
    ~KeyReleaseEvent() override = default;
};
