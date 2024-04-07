/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** EventHandler.hpp
*/

#pragma once

#include <vector>

#include "common/events/window/window.hpp"
#include "common/events/mouse/mouse.hpp"
#include "common/events/key/key.hpp"

namespace arcade::graphics::ncurses::window {
    class EventsHandler;
    class Window;
}

class arcade::graphics::ncurses::window::EventsHandler {
public:
    explicit EventsHandler(Window &window);
    ~EventsHandler() = default;

    typedef EventPtr (*EventHandler)(int code, Window &window);

    /**
     * @brief Handle events from NCURSES
     * @param window Window object
     * @return Vector of events
     */
    std::vector<EventPtr> handleEvents();

private:

    // static EventHandler _getHandler(sf::Event::EventType type);


    /**
     * @brief Handle key press event
     * @param code Code of the key
     * @return EventPtr, depending on the key
     */
    EventPtr _handleKeyPressEvent(int code);

    /**
     * @brief Handle Function key event, F1 to F12
     * @param code Code of the key
     * @return EventPtr, F1 to F12
     */
    EventPtr _handleFunctionKey(int code);

    /**
     * @brief Handle arrow key event, UP, DOWN, LEFT, RIGHT
     * @param code Code of the key
     * @return EventPtr, UP, DOWN, LEFT, RIGHT
     */
    EventPtr _handleArrowKey(int code);

    /**
     * @brief Handle char key event
     * @param code Code of the key
     * @return EventPtr, depending on the key
     */
    EventPtr _handleCharKey(int code);

    window::Window &_window;
};
