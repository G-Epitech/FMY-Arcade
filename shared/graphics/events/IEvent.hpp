/*
** EPITECH PROJECT, 2024
** arcade-shared
** File description:
** IEvent
*/

#pragma once

#include <memory>

namespace shared::graphics::events {
    class IEvent;

    /// @brief Event type
    typedef enum {
        /// @brief Key pressed
        KEY_PRESS,
        /// @brief Key released
        KEY_RELEASE,
        /// @brief Mouse button pressed
        MOUSE_BTN_PRESS,
        /// @brief Mouse button released
        MOUSE_BTN_RELEASE,
        /// @brief Mouse moved
        MOUSE_MOVE,
        /// @brief Window closed
        WINDOW_CLOSE,
        /// @brief Window resized
        WINDOW_RESIZE,
    } EventType;

    /// @brief Event pointer
    typedef std::shared_ptr<IEvent> EventPtr;
}

/**
 * @brief Interface for the event object
 * 
 */
class shared::graphics::events::IEvent {
public:
    virtual ~IEvent() = default;

    /**
     * @brief Event type
     */
    virtual EventType getType() const noexcept = 0;
};
