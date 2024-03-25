/*
** EPITECH PROJECT, 2024
** arcade-shared
** File description:
** AKeyEvent
*/

#pragma once

#include "AKeyEvent.hpp"

namespace shared::graphics::events {
  class KeyPressEvent;
}

class shared::graphics::events::KeyPressEvent: public AKeyEvent<EventType::KEY_PRESS> {
  public:
    KeyPressEvent(KeyType keyType, KeyCode keyCode): AKeyEvent(keyType, keyCode) {}
};
