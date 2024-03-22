/*
** EPITECH PROJECT, 2024
** arcade-shared
** File description:
** IMouseEvent
*/

#pragma once

#include "AMouseButtonEvent.hpp"

namespace shared::graphics::events
{
  class MouseButtonPressEvent;
}

class shared::graphics::events::MouseButtonPressEvent :
  public AMouseButtonEvent<EventType::MOUSE_BTN_PRESS>
{
  public:
    MouseButtonPressEvent(MouseButton button, types::Vector2f position)
      : AMouseButtonEvent(button, position) {}
    ~MouseButtonPressEvent() = default;
};
