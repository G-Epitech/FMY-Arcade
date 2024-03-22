/*
** EPITECH PROJECT, 2024
** arcade-shared
** File description:
** IMouseEvent
*/

#pragma once

#include "AMouseEvent.hpp"

namespace shared::graphics::events
{
  class MouseMoveEvent;
}

class shared::graphics::events::MouseMoveEvent : public AMouseEvent<EventType::MOUSE_MOVE>
{
   public:
    MouseMoveEvent(types::Vector2f position) : AMouseEvent(position) {}
    ~MouseMoveEvent() = default;
};
