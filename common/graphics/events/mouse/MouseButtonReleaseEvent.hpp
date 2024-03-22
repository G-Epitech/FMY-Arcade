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
  class MouseButtonReleaseEvent;
}

class shared::graphics::events::MouseButtonReleaseEvent :
  public AMouseButtonEvent<EventType::MOUSE_BTN_RELEASE>
{
  public:
    MouseButtonReleaseEvent(MouseButton button, types::Vector2f position)
      : AMouseButtonEvent(button, position) {}
    ~MouseButtonReleaseEvent() = default;
};
