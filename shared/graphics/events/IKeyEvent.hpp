/*
** EPITECH PROJECT, 2024
** arcade-shared
** File description:
** AKeyEvent
*/

#pragma once

#include "IEvent.hpp"

namespace shared::graphics::events {
    class IKeyEvent;
}

/**
 * @brief Interface for the key event object
 * 
 */
class shared::graphics::events::IKeyEvent : public virtual IEvent {
public:
    virtual ~IKeyEvent() = default;

    /// @brief Key type
    typedef enum {
        /// @brief Control key (`Ctrl`, `Shift`, `Alt`)
        CONTROL,
        /// @brief Arrow key (`Up`, `Down`, `Left`, `Right`)
        ARROW,
        /// @brief Function key (`F1`, `F2`, `F3`, etc.)
        FUNC,
        /// @brief ASCII character key
        CHAR,
        /// @brief Unknown key
        UNKNOWN
    } KeyType;

    /// @brief Control key code
    typedef enum {
        /// @brief CTRL key
        CTRL,
        /// @brief SHIFT key
        SHIFT,
        /// @brief ALT key
        ALT
    } ControlCode;

    /// @brief Arrow key code
    typedef enum {
        /// @brief UP arrow key
        UP,
        /// @brief DOWN arrow key
        DOWN,
        /// @brief LEFT arrow key
        LEFT,
        /// @brief RIGHT arrow key
        RIGHT
    } ArrowCode;

    /// @brief Key code
    typedef union {
        /// @brief Control key
        ControlCode control;
        /// @brief Arrow key
        ArrowCode arrow;
        /// @brief ASCII character value
        char character;
        /// @brief Function key number
        unsigned char func;
    } KeyCode;

    /**
     * @brief Key code content
     *
     * @return Content of the key code
     */
    virtual const KeyCode getKeyCode(void) const noexcept = 0;

    /**
     * @brief Key type
     *
     * @return Type of the key pressed
     */
    virtual const KeyType getKeyType(void) const noexcept = 0;
};
