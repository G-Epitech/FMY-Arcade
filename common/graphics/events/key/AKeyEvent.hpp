/*
** EPITECH PROJECT, 2024
** arcade-shared
** File description:
** AKeyEvent
*/

#pragma once

#include "../IEvent.hpp"

namespace shared::graphics::events {
  template<EventType T>
  class AKeyEvent;

  typedef enum
  {
    CONTROL, // Control key (`Ctrl`, `Shift`, `Alt`)
    ARROW,   // Arrow key (`Up`, `Down`, `Left`, `Right`)
    FUNC,    // Function key (`F1`, `F2`, `F3`, etc.)
    CHAR,    // Character key (`a`, `1`, `&`, etc.)
    UNKNOWN  // Unknown key
  } KeyType;

  typedef enum
  {
    CTRL,  // `Ctrl` key
    SHIFT, // `Shift` key
    ALT    // `Alt` key
  } ControlCode;

  typedef enum
  {
    UP,   // `Up` arrow key
    DOWN, // `Down` arrow key
    LEFT, // `Left` arrow key
    RIGHT // `Right` arrow key
  } ArrowCode;

  typedef union
  {
    ControlCode control;     // Control key
    ArrowCode arrow;         // Arrow key
    char character; // ASCII character value
    unsigned char func;      // Function key number
  } KeyCode;
}

template<shared::graphics::events::EventType T>
class shared::graphics::events::AKeyEvent: public IEvent {
  public:
    ~AKeyEvent() = default;

    /**
     * @brief Event type
     *
     */
    const EventType getType(void) const noexcept
    {
      return this->_type;
    }

    /**
     * @brief Key code content
     *
     */
    const KeyCode getKeyCode(void) const noexcept
    {
      return this->_keyCode;
    }

    /**
     * @brief Key type
     *
     */
    const KeyType getKeyType(void) const noexcept
    {
      return this->_keyType;
    }

  protected:
    AKeyEvent(KeyType keyType, KeyCode keyCode) : _keyType(keyType), _keyCode(keyCode) {}

    EventType _type = T;
    KeyType   _keyType;
    KeyCode   _keyCode;
};
