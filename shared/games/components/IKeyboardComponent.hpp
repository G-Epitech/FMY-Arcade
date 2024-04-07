/*
** EPITECH PROJECT, 2024
** arcade-shared
** File description:
** IKeyboardComponent
*/

#pragma once

#include "../IGame.hpp"
#include "IComponent.hpp"

namespace shared::games::components {
    class IKeyboardComponent;
}

/**
 * @brief Interface of a keyboard component
 * 
 */
class shared::games::components::IKeyboardComponent: public virtual IComponent {
public:

    /// @brief Type of the key
    typedef enum {
        /// @brief Control key (`Ctrl`, `Shift`, `Alt`)
        CONTROL,
        /// @brief Arrow key (`Up`, `Down`, `Left`, `Right`)
        ARROW,
        /// @brief Function key (`F1`, `F2`, `F3`, etc.)
        FUNC,
        /// @brief Character key (`a`, `1`, `&`, etc.)
        CHAR,
        /// @brief Unknown key
        UNKNOWN
    } KeyType;

    /// @brief Control key code
    typedef enum {
        /// @brief `Ctrl` key
        CTRL,
        /// @brief `Shift` key
        SHIFT,
        /// @brief `Alt` key
        ALT
    } ControlCode;

    /// @brief Arrow key code
    typedef enum {
        /// @brief `Up` arrow key
        UP,
        /// @brief `Down` arrow key
        DOWN,
        /// @brief `Left` arrow key
        LEFT,
        /// @brief `Right` arrow key
        RIGHT
    } ArrowCode;

    /// @brief Function key code union
    typedef union {
        /// @brief Function key number
        ControlCode control;
        /// @brief Control key code
        ArrowCode arrow;
        /// @brief Arrow key code
        char character;
        /// @brief Character key code
        unsigned char func;
    } KeyCode;

    /// @brief Key data
    typedef struct {
        /// @brief Key code. Interpretation depends on the type
        KeyCode code;
        /// @brief Type of the key
        KeyType type;
    } KeyData;

    virtual ~IKeyboardComponent() = default;

    /**
     * @brief On key pressed event handler for the entity
     * @param ctx Context of the game
     * @param keyData Key data of key pressed
     */
    virtual void onKeyPress(std::shared_ptr<IGame> ctx, KeyData keyData) = 0;

    /**
     * @brief On key release event handler for the entity
     * @param ctx Context of the game
     * @param keyData Key data of key released
     */
    virtual void onKeyRelease(std::shared_ptr<IGame> ctx, KeyData keyData) = 0;
};
