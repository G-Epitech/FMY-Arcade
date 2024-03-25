/*
** EPITECH PROJECT, 2024
** arcade-shared
** File description:
** IWindowResizeEvent
*/

#pragma once

#include "../IEvent.hpp"
#include "../../../types/types.hpp"

namespace shared::graphics::events {
  class WindowResizeEvent;
}

class shared::graphics::events::WindowResizeEvent: public IEvent {
  public:
    WindowResizeEvent(types::Vector2u newSize) : _newSize(newSize) {}
    ~WindowResizeEvent() = default;

    /**
     * @brief Event type
     *
     */
    const EventType getType() const noexcept
    {
      return WINDOW_RESIZE;
    }

    /**
     * @brief Get the new window size
     *
     * @return New window size
     */
    const types::Vector2u &getNewSize() const noexcept
    {
      return this->_newSize;
    }

    protected:
      types::Vector2u _newSize;
};
