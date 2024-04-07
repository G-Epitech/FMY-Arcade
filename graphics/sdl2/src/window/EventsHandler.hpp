/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** EventHandler.hpp
*/

#pragma once

#include <vector>

#include "sdl/window/Window.hpp"
#include "common/events/window/window.hpp"
#include "common/events/mouse/mouse.hpp"
#include "common/events/key/key.hpp"

namespace arcade::graphics::sdl2::window {
    class EventsHandler;
    class Window;
}

class arcade::graphics::sdl2::window::EventsHandler {
public:
    explicit EventsHandler(Window &window);
    ~EventsHandler() = default;

    typedef EventPtr (*EventHandler)(sdl::Event &event, Window &window);

    /**
     * @brief Handle events from SDL2
     * @param window Window object
     * @return Vector of events
     */
    std::vector<EventPtr> handleEvents();

private:

    static EventHandler _getHandler(sdl::EventType type);

    /**
     * @brief Handle control key event if it's a control key
     * @param event Event from SDL2
     * @param code Code of the key to set
     * @return Status of handling
     */
    static bool _handleControlKey(sdl::KeyboardEvent &event, IKeyEvent::KeyCode &code);

    /**
     * @brief Handle control key event if it's an arrow key
     * @param event Event from SDL2
     * @param code Code of the key to set
     * @return Status of handling
     */
    static bool _handleArrowKey(sdl::KeyboardEvent &event, IKeyEvent::KeyCode &code);

    /**
     * @brief Handle control key event if it's a function key
     * @param event Event from SDL2
     * @param code Code of the key to set
     * @return Status of handling
     */
    static bool _handleFunctionKey(sdl::KeyboardEvent &event, IKeyEvent::KeyCode &code);

    /**
     * @brief Handle control key event if it's a char key
     * @param event Event from SDL2
     * @param code Code of the key to set
     * @return Status of handling
     */
    static bool _handleCharKey(sdl::KeyboardEvent &event, IKeyEvent::KeyCode &code);

    /**
     * @brief Handle key press event
     * @param event Event from SDL2
     * @param window Window object
     * @return Pointer to created event or null if not handled
     */
    static EventPtr _handleKeyPressEvent(sdl::Event &event, Window &window);

    /**
     * @brief Handle key release event
     * @param event Event from SDL2
     * @param window Window object
     * @return Pointer to created event or null if not handled
     */
    static EventPtr _handleKeyReleaseEvent(sdl::Event &event, Window &window);

    /**
     * @brief Handle mouse button press event
     * @param event Event from SDL2
     * @param window Window object
     * @return Pointer to created event or null if not handled
     */
    static EventPtr _handleMouseButtonPressEvent(sdl::Event &event, Window &window);

    /**
     * @brief Handle mouse button release event
     * @param event Event from SDL2
     * @param window Window object
     * @return Pointer to created event or null if not handled
     */
    static  EventPtr _handleMouseBtnReleaseEvent(sdl::Event &event, Window &window);

    /**
     * @brief Handle mouse move event
     * @param event Event from SDL2
     * @param window Window object
     * @return Pointer to created event or null if not handled
     */
    static EventPtr _handleMouseMoveEvent(sdl::Event &event, Window &window);

    /**
     * @brief Handle window close event
     * @param event Event from SDL2
     * @param window Window object
     * @return Pointer to created event or null if not handled
     */
    static EventPtr _handleWindowCloseEvent(sdl::Event &event, Window &window);

    /**
     * @brief Handle window resize event
     * @param event Event from SDL2
     * @param window Window object
     * @return Pointer to created event or null if not handled
     */
    static EventPtr _handleWindowResizeEvent(sdl::Event &event, Window &window);

    /**
     * @brief Resolve position of the event to convert it in tiles unit
     * @param position Position to resolve
     * @param window Window object of which relate the position
     * @return Resolved position
     */
    static Vector2i _resolvePosition(Vector2i position, Window &window);

    window::Window &_window;
};
