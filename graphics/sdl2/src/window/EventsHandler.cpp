/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** EventHandler.cpp
*/

#include <memory>
#include <map>
#include "Window.hpp"
#include "EventsHandler.hpp"
#include "utils/compiler.hpp"

using namespace arcade::graphics::sdl2::window;

EventsHandler::EventHandler EventsHandler::_getHandler(sdl::EventType type) {
    static std::map<sdl::EventType, EventHandler> handlers = {
        {SDL_KEYDOWN,          _handleKeyPressEvent},
        {SDL_KEYUP,         _handleKeyReleaseEvent},
        {SDL_MOUSEBUTTONDOWN,  _handleMouseButtonPressEvent},
        {SDL_MOUSEBUTTONUP, _handleMouseBtnReleaseEvent},
        {SDL_MOUSEMOTION,          _handleMouseMoveEvent},
        {SDL_WINDOWEVENT,      _handleWindowEvents}
    };
    auto handler = handlers.find(type);

    return handler != handlers.end() ? handler->second : nullptr;
}

EventsHandler::EventsHandler(Window &window): _window(window) {}

std::vector<EventPtr> EventsHandler::handleEvents() {
    std::vector<EventPtr> events;
    sdl::Event originalEvent{};

    while (sdl::Window::pollEvent(originalEvent)) {
        auto handler = _getHandler(static_cast<sdl::EventType>(originalEvent.type));
        auto event = handler ? handler(originalEvent, _window) : nullptr;

        if (event)
            events.push_back(event);
    }
    return events;
}

bool EventsHandler::_handleControlKey(
    sdl::KeyboardEvent &event,
    IKeyEvent::KeyCode &code
) {
    switch (event.keysym.sym) {
        case SDLK_LCTRL:
        case SDLK_RCTRL:
            code.control = IKeyEvent::ControlCode::CTRL;
            return true;

        case SDLK_LSHIFT:
        case SDLK_RSHIFT:
            code.control = IKeyEvent::ControlCode::SHIFT;
            return true;

        case SDLK_LALT:
        case SDLK_RALT:
            code.control = IKeyEvent::ControlCode::ALT;
            return true;

        default:
            return false;
    }
}

bool EventsHandler::_handleArrowKey(
    sdl::KeyboardEvent &event,
    IKeyEvent::KeyCode &code
) {
    switch (event.keysym.sym) {
        case SDLK_LEFT:
            code.arrow = IKeyEvent::ArrowCode::LEFT;
            return true;
        case SDLK_RIGHT:
            code.arrow = IKeyEvent::ArrowCode::RIGHT;
            return true;
        case SDLK_UP:
            code.arrow = IKeyEvent::ArrowCode::UP;
            return true;
        case SDLK_DOWN:
            code.arrow = IKeyEvent::ArrowCode::DOWN;
            return true;
        default:
            return false;
    }
}

bool EventsHandler::_handleFunctionKey(
    sdl::KeyboardEvent &event,
    IKeyEvent::KeyCode &code
)
{
    if (event.keysym.sym >= SDLK_F1 && event.keysym.sym <= SDLK_F12) {
        code.func = static_cast<unsigned char>(event.keysym.sym - SDLK_F1 + 1);
        return true;
    } else {
        return false;
    }
}

bool EventsHandler::_handleCharKey(
    sdl::KeyboardEvent &event,
    IKeyEvent::KeyCode &code
) {
    static const std::map<sdl::Keycode, char> specials = {
        {SDLK_SPACE, ' '},
        {SDLK_LEFTBRACKET, '['},
        {SDLK_RIGHTBRACKET, ']'},
        {SDLK_SEMICOLON, ';'},
        {SDLK_COMMA, ','},
        {SDLK_PERIOD, '.'},
        {SDLK_QUOTE, '\''},
        {SDLK_SLASH, '/'},
        {SDLK_BACKSLASH, '\\'},
        {SDLK_EQUALS, '='},
        {SDLK_RETURN, '\n'},
        {SDLK_BACKSPACE, '\b'},
        {SDLK_TAB, '\t'},
        {SDLK_ESCAPE, 0x1B},
        {SDLK_PLUS, '+'},
        {SDLK_MINUS, '-'},
        {SDLK_ASTERISK, '*'},
        {SDLK_SLASH, '/'}
    };
    auto sym = event.keysym.sym;

    if (sym >= SDLK_a && sym <= SDLK_z) {
        code.character = static_cast<char>(sym - SDLK_a + 'a');
    } else if (sym >= SDLK_0 && sym <= SDLK_9) {
        code.character = static_cast<char>(sym - SDLK_0 + '0');
    } else {
        auto special = specials.find(sym);

        if (special != specials.end()) {
            code.character = special->second;
        } else {
            return false;
        }
    }
    return true;
}

EventPtr EventsHandler::_handleKeyPressEvent(sdl::Event &event, unused Window &window) {
    IKeyEvent::KeyType type = IKeyEvent::KeyType::UNKNOWN;
    IKeyEvent::KeyCode code;

    if (_handleControlKey(event.key, code))
        type = IKeyEvent::KeyType::CONTROL;
    else if (_handleArrowKey(event.key, code))
        type = IKeyEvent::KeyType::ARROW;
    else if (_handleFunctionKey(event.key, code))
        type = IKeyEvent::KeyType::FUNC;
    else if (_handleCharKey(event.key, code))
        type = IKeyEvent::KeyType::CHAR;
    return std::make_shared<KeyPressEvent>(type, code);
}

EventPtr EventsHandler::_handleKeyReleaseEvent(
    sdl::Event &event,
    unused Window &window
) {
    IKeyEvent::KeyType type = IKeyEvent::KeyType::UNKNOWN;
    IKeyEvent::KeyCode code;

    if (_handleControlKey(event.key, code))
        type = IKeyEvent::KeyType::CONTROL;
    else if (_handleArrowKey(event.key, code))
        type = IKeyEvent::KeyType::ARROW;
    else if (_handleFunctionKey(event.key, code))
        type = IKeyEvent::KeyType::FUNC;
    else if (_handleCharKey(event.key, code))
        type = IKeyEvent::KeyType::CHAR;
    return std::make_shared<KeyReleaseEvent>(type, code);
}

EventPtr EventsHandler::_handleWindowEvents(
    sdl::Event &event,
    unused Window &window
) {
    if (event.window.event == SDL_WINDOWEVENT_CLOSE)
        return std::make_shared<WindowCloseEvent>();
    if (event.window.event == SDL_WINDOWEVENT_RESIZED)
        return std::make_shared<WindowResizeEvent>();
    return nullptr;

}

EventPtr EventsHandler::_handleMouseMoveEvent(
    sdl::Event &event,
    Window &window
) {
    return std::make_shared<MouseMoveEvent>(
        window.pixelsToTiles(Vector2i(event.motion.x, event.motion.y))
    );
}

EventPtr EventsHandler::_handleMouseButtonPressEvent(
    sdl::Event &event,
    Window &window
) {
    Vector2f pos = window.pixelsToTiles(Vector2i(event.button.x, event.button.y));

    if (event.button.button == SDL_BUTTON_LEFT)
        return std::make_shared<MouseButtonPressEvent>(pos, IMouseButtonEvent::MouseButton::LEFT);
    else if (event.button.button == SDL_BUTTON_RIGHT)
        return std::make_shared<MouseButtonPressEvent>(pos, IMouseButtonEvent::MouseButton::RIGHT);
    else
        return nullptr;
}


EventPtr EventsHandler::_handleMouseBtnReleaseEvent(
    sdl::Event &event,
    unused Window &window
) {
    Vector2f pos = window.pixelsToTiles(Vector2i(event.button.x, event.button.y));

    if (event.button.button == SDL_BUTTON_LEFT)
        return std::make_shared<MouseButtonReleaseEvent>(pos, IMouseButtonEvent::MouseButton::LEFT);
    else if (event.button.button == SDL_BUTTON_RIGHT)
        return std::make_shared<MouseButtonReleaseEvent>(pos, IMouseButtonEvent::MouseButton::RIGHT);
    else
        return nullptr;
}
