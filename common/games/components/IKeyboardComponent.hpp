/*
** EPITECH PROJECT, 2024
** arcade-shared
** File description:
** IKeyboardComponent
*/

#pragma once

#include "IComponent.hpp"

namespace shared::games::components {
  class IKeyboardComponent;

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
    char character;          // ASCII character value
    unsigned char func;      // Function key number
  } KeyCode;

  typedef struct
  {
    KeyCode code; // Key code. Interpretation depends on the type
    KeyType type; // Type of the key
  } KeyData;
}

class shared::games::components::IKeyboardComponent: public virtual IComponent
{
public:
  virtual ~IKeyboardComponent() = default;

  /**
   * @brief On key pressed event handler for the entity
   * @param ctx Context of the game
   * @param keyData Key data of key pressed
   */
  virtual void onKeyPress(game::UniqueGame &ctx, KeyData keyData) = 0;

  /**
   * @brief On key release event handler for the entity
   * @param ctx Context of the game
   * @param keyData Key data of key released
   */
  virtual void onKeyRelease(game::UniqueGame &ctx, KeyData keyData) = 0;
};
