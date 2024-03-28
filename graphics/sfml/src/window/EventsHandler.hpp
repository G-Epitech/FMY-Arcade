/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** EventHandler.hpp
*/

#pragma once

#include <vector>
#include <SFML/Graphics.hpp>

#include "common/events/window/window.hpp"
#include "common/events/mouse/mouse.hpp"
#include "common/events/key/key.hpp"

namespace arcade::graphics::sfml::events {
    class EventsHandler;
}

class arcade::graphics::sfml::events::EventsHandler {
public:
    EventsHandler() = delete;
    ~EventsHandler() = delete;

    typedef EventPtr (*EventHandler)(sf::Event &event, sf::RenderWindow &window);

    /**
     * @brief Handle events from SFML
     * @param window Window object
     * @return Vector of events
     */
    static std::vector<EventPtr> handleEvents(sf::RenderWindow &window);

private:

    static EventHandler _getHandler(sf::Event::EventType type);

    /**
     * @brief Handle control key event if it's a control key
     * @param event Event from SFML
     * @param code Code of the key to set
     * @return Status of handling
     */
    static bool _handleControlKey(sf::Event::KeyEvent event, IKeyEvent::KeyCode &code);

    /**
     * @brief Handle control key event if it's an arrow key
     * @param event Event from SFML
     * @param code Code of the key to set
     * @return Status of handling
     */
    static bool _handleArrowKey(sf::Event::KeyEvent event, IKeyEvent::KeyCode &code);

    /**
     * @brief Handle control key event if it's a function key
     * @param event Event from SFML
     * @param code Code of the key to set
     * @return Status of handling
     */
    static bool _handleFunctionKey(sf::Event::KeyEvent event, IKeyEvent::KeyCode &code);

    /**
     * @brief Handle control key event if it's a char key
     * @param event Event from SFML
     * @param code Code of the key to set
     * @return Status of handling
     */
    static bool _handleCharKey(sf::Event::KeyEvent event, IKeyEvent::KeyCode &code);

    /**
     * @brief Handle key press event
     * @param event Event from SFML
     * @param window Window object
     * @return Pointer to created event or null if not handled
     */
    static EventPtr _handleKeyPressEvent(sf::Event &event, sf::RenderWindow &window);

    /**
     * @brief Handle key release event
     * @param event Event from SFML
     * @param window Window object
     * @return Pointer to created event or null if not handled
     */
    static EventPtr _handleKeyReleaseEvent(sf::Event &event, sf::RenderWindow &window);

    /**
     * @brief Handle mouse button press event
     * @param event Event from SFML
     * @param window Window object
     * @return Pointer to created event or null if not handled
     */
    static EventPtr _handleMouseButtonPressEvent(sf::Event &event, sf::RenderWindow &window);

    /**
     * @brief Handle mouse button release event
     * @param event Event from SFML
     * @param window Window object
     * @return Pointer to created event or null if not handled
     */
    static EventPtr _handleMouseBtnReleaseEvent(sf::Event &event, sf::RenderWindow &window);

    /**
     * @brief Handle mouse move event
     * @param event Event from SFML
     * @param window Window object
     * @return Pointer to created event or null if not handled
     */
    static EventPtr _handleMouseMoveEvent(sf::Event &event, sf::RenderWindow &window);

    /**
     * @brief Handle window close event
     * @param event Event from SFML
     * @param window Window object
     * @return Pointer to created event or null if not handled
     */
    static EventPtr _handleWindowCloseEvent(sf::Event &event, sf::RenderWindow &window);

    /**
     * @brief Handle window resize event
     * @param event Event from SFML
     * @param window Window object
     * @return Pointer to created event or null if not handled
     */
    static EventPtr _handleWindowResizeEvent(sf::Event &event, sf::RenderWindow &window);
};
