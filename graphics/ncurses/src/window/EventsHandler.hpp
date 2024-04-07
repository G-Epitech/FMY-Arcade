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

    // typedef EventPtr (*EventHandler)(sf::Event &event, Window &window);

    /**
     * @brief Handle events from NCURSES
     * @param window Window object
     * @return Vector of events
     */
    std::vector<EventPtr> handleEvents();

private:

    // static EventHandler _getHandler(sf::Event::EventType type);

    // /**
    //  * @brief Handle control key event if it's a control key
    //  * @param event Event from NCURSES
    //  * @param code Code of the key to set
    //  * @return Status of handling
    //  */
    // static bool _handleControlKey(sf::Event::KeyEvent event, IKeyEvent::KeyCode &code);

    // /**
    //  * @brief Handle control key event if it's an arrow key
    //  * @param event Event from NCURSES
    //  * @param code Code of the key to set
    //  * @return Status of handling
    //  */
    // static bool _handleArrowKey(sf::Event::KeyEvent event, IKeyEvent::KeyCode &code);

    // /**
    //  * @brief Handle control key event if it's a function key
    //  * @param event Event from NCURSES
    //  * @param code Code of the key to set
    //  * @return Status of handling
    //  */
    // static bool _handleFunctionKey(sf::Event::KeyEvent event, IKeyEvent::KeyCode &code);

    // /**
    //  * @brief Handle control key event if it's a char key
    //  * @param event Event from NCURSES
    //  * @param code Code of the key to set
    //  * @return Status of handling
    //  */
    // static bool _handleCharKey(sf::Event::KeyEvent event, IKeyEvent::KeyCode &code);

    // /**
    //  * @brief Handle key press event
    //  * @param event Event from NCURSES
    //  * @param window Window object
    //  * @return Pointer to created event or null if not handled
    //  */
    // static EventPtr _handleKeyPressEvent(sf::Event &event, Window &window);

    // /**
    //  * @brief Handle key release event
    //  * @param event Event from NCURSES
    //  * @param window Window object
    //  * @return Pointer to created event or null if not handled
    //  */
    // static EventPtr _handleKeyReleaseEvent(sf::Event &event, Window &window);

    // /**
    //  * @brief Handle mouse button press event
    //  * @param event Event from NCURSES
    //  * @param window Window object
    //  * @return Pointer to created event or null if not handled
    //  */
    // static EventPtr _handleMouseButtonPressEvent(sf::Event &event, Window &window);

    // /**
    //  * @brief Handle mouse button release event
    //  * @param event Event from NCURSES
    //  * @param window Window object
    //  * @return Pointer to created event or null if not handled
    //  */
    // static  EventPtr _handleMouseBtnReleaseEvent(sf::Event &event, Window &window);

    // /**
    //  * @brief Handle mouse move event
    //  * @param event Event from NCURSES
    //  * @param window Window object
    //  * @return Pointer to created event or null if not handled
    //  */
    // static EventPtr _handleMouseMoveEvent(sf::Event &event, Window &window);

    // /**
    //  * @brief Handle window close event
    //  * @param event Event from NCURSES
    //  * @param window Window object
    //  * @return Pointer to created event or null if not handled
    //  */
    // static EventPtr _handleWindowCloseEvent(sf::Event &event, Window &window);

    // /**
    //  * @brief Handle window resize event
    //  * @param event Event from NCURSES
    //  * @param window Window object
    //  * @return Pointer to created event or null if not handled
    //  */
    // static EventPtr _handleWindowResizeEvent(sf::Event &event, Window &window);

    // /**
    //  * @brief Resolve position of the event to convert it in tiles unit
    //  * @param position Position to resolve
    //  * @param window Window object of which relate the position
    //  * @return Resolved position
    //  */
    // static Vector2i _resolvePosition(Vector2i position, Window &window);

    window::Window &_window;
};
