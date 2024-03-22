/*
** EPITECH PROJECT, 2024
** arcade-shared
** File description:
** IMouseEvent
*/

#pragma once

#include "../../../types/types.hpp"
#include "../IEvent.hpp"

namespace shared::graphics::events
{
  template<EventType T>
  class AMouseEvent;

  typedef enum {
    LEFT,
    RIGHT
  } MouseButton;
}

template<shared::graphics::events::EventType T>
class shared::graphics::events::AMouseEvent : public IEvent
{
   public:
    ~AMouseEvent() = default;

    /**
     * @brief Event type
     *
     */
    const EventType getType(void) const noexcept {
      return T;
    }

    /**
     * @brief Mouse position
     *
     */
    const shared::types::Vector2f getPosition(void) const noexcept {
      return this->_position;
    }

  protected:
    AMouseEvent(types::Vector2f position): _position(position) {}

    types::Vector2f _position;
};
