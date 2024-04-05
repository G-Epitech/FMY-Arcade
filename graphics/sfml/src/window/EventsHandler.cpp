/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** EventHandler.cpp
*/

#include <memory>

#include "Window.hpp"
#include "EventsHandler.hpp"
#include "utils/compiler.hpp"

using namespace arcade::graphics::sfml::window;

EventsHandler::EventHandler EventsHandler::_getHandler(sf::Event::EventType type) {
    static std::map<sf::Event::EventType, EventHandler> handlers = {
        {sf::Event::KeyPressed,          _handleKeyPressEvent},
        {sf::Event::KeyReleased,         _handleKeyReleaseEvent},
        {sf::Event::MouseButtonPressed,  _handleMouseButtonPressEvent},
        {sf::Event::MouseButtonReleased, _handleMouseBtnReleaseEvent},
        {sf::Event::MouseMoved,          _handleMouseMoveEvent},
        {sf::Event::Closed,              _handleWindowCloseEvent},
        {sf::Event::Resized,             _handleWindowResizeEvent}
    };
    auto handler = handlers.find(type);

    return handler != handlers.end() ? handler->second : nullptr;
}

EventsHandler::EventsHandler(Window &window) : _window(window) {}

std::vector<EventPtr> EventsHandler::handleEvents() {
    std::vector<EventPtr> events;
    sf::Event SFMLEvent{};

    while (_window.getInnerWindow().pollEvent(SFMLEvent)) {
        auto handler = _getHandler(SFMLEvent.type);
        auto event = handler ? handler(SFMLEvent, _window) : nullptr;

        if (event)
            events.push_back(event);
    }
    return events;
}

bool EventsHandler::_handleControlKey(
    sf::Event::KeyEvent event,
    unused IKeyEvent::KeyCode &code
) {
    switch (event.code) {
        case sf::Keyboard::LControl:
        case sf::Keyboard::RControl:
        case sf::Keyboard::LShift:
        case sf::Keyboard::RShift:
        case sf::Keyboard::LAlt:
        case sf::Keyboard::RAlt:
            return true;

        default:
            return false;
    }
}

bool EventsHandler::_handleArrowKey(
    sf::Event::KeyEvent event,
    IKeyEvent::KeyCode &code
) {
    switch (event.code) {
        case sf::Keyboard::Left:
            code.arrow = IKeyEvent::ArrowCode::LEFT;
            return true;
        case sf::Keyboard::Right:
            code.arrow = IKeyEvent::ArrowCode::RIGHT;
            return true;
        case sf::Keyboard::Up:
            code.arrow = IKeyEvent::ArrowCode::UP;
            return true;
        case sf::Keyboard::Down:
            code.arrow = IKeyEvent::ArrowCode::DOWN;
            return true;
        default:
            return false;
    }
}

bool EventsHandler::_handleFunctionKey(
    sf::Event::KeyEvent event,
    IKeyEvent::KeyCode &code
) {
    if (event.code >= sf::Keyboard::F1 && event.code <= sf::Keyboard::F12) {
        code.func = event.code - sf::Keyboard::F1 + 1;
        return true;
    } else {
        return false;
    }
}

bool EventsHandler::_handleCharKey(
    sf::Event::KeyEvent event,
    IKeyEvent::KeyCode &code
) {
    static const std::map<sf::Keyboard::Key, char> specials = {
        {sf::Keyboard::Space,     ' '},
        {sf::Keyboard::LBracket,  '['},
        {sf::Keyboard::RBracket,  ']'},
        {sf::Keyboard::Semicolon, ';'},
        {sf::Keyboard::Comma,     ','},
        {sf::Keyboard::Period,    '.'},
        {sf::Keyboard::Quote,     '\''},
        {sf::Keyboard::Slash,     '/'},
        {sf::Keyboard::Backslash, '\\'},
        {sf::Keyboard::Tilde,     '~'},
        {sf::Keyboard::Equal,     '='},
        {sf::Keyboard::Hyphen,    '-'},
        {sf::Keyboard::Enter,     '\n'},
        {sf::Keyboard::Backspace, '\b'},
        {sf::Keyboard::Tab,       '\t'},
        {sf::Keyboard::Escape,    0x1B},
        {sf::Keyboard::Add,       '+'},
        {sf::Keyboard::Subtract,  '-'},
        {sf::Keyboard::Multiply,  '*'},
        {sf::Keyboard::Divide,    '/'}
    };

    if (event.code >= sf::Keyboard::A && event.code <= sf::Keyboard::Z) {
        code.character = static_cast<char>(event.code - sf::Keyboard::A + 'a');
    } else if (event.code >= sf::Keyboard::Num0 && event.code <= sf::Keyboard::Num9) {
        code.character = static_cast<char>(event.code - sf::Keyboard::Num0 + '0');
    } else if (event.code >= sf::Keyboard::Numpad0 && event.code <= sf::Keyboard::Numpad9) {
        code.character = static_cast<char>(event.code - sf::Keyboard::Numpad0 + '0');
    } else {
        auto special = specials.find(event.code);

        if (special != specials.end()) {
            code.character = special->second;
        } else {
            return false;
        }
    }
    return true;
}

EventPtr EventsHandler::_handleKeyPressEvent(sf::Event &event, unused Window &window) {
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
    sf::Event &event,
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

EventPtr EventsHandler::_handleWindowCloseEvent(
    unused sf::Event &event,
    unused Window &window
) {
    return std::make_shared<WindowCloseEvent>();
}

EventPtr EventsHandler::_handleWindowResizeEvent(
    unused sf::Event &event,
    Window &window
) {
    window.onResize();
    return std::make_shared<WindowResizeEvent>();
}

EventPtr EventsHandler::_handleMouseMoveEvent(
    sf::Event &event,
    Window &window
) {
    auto pos = window.mapPositionToTile({
         event.mouseMove.x,
         event.mouseMove.y
    });

    return pos.x >= 0 && pos.y >= 0
            ? std::make_shared<MouseMoveEvent>(pos)
            : nullptr;
}

EventPtr EventsHandler::_handleMouseButtonPressEvent(
    sf::Event &event,
    Window &window
) {
    auto pos = window.mapPositionToTile({
        event.mouseButton.x,
        event.mouseButton.y
    });

    if (pos.x < 0 || pos.y < 0)
        return nullptr;
    if (event.mouseButton.button == sf::Mouse::Button::Left)
        return std::make_shared<MouseButtonPressEvent>(pos, IMouseButtonEvent::MouseButton::LEFT);
    else if (event.mouseButton.button == sf::Mouse::Button::Right)
        return std::make_shared<MouseButtonPressEvent>(pos, IMouseButtonEvent::MouseButton::RIGHT);
    return nullptr;
}

EventPtr EventsHandler::_handleMouseBtnReleaseEvent(
    sf::Event &event,
    unused Window &window
) {
    auto pos = window.mapPositionToTile({
        event.mouseMove.x,
        event.mouseMove.y
    });

    if (pos.x < 0 || pos.y < 0)
        return nullptr;
    if (event.mouseButton.button == sf::Mouse::Button::Left)
        return std::make_shared<MouseButtonReleaseEvent>(pos, IMouseButtonEvent::MouseButton::LEFT);
    else if (event.mouseButton.button == sf::Mouse::Button::Right)
        return std::make_shared<MouseButtonReleaseEvent>(pos, IMouseButtonEvent::MouseButton::RIGHT);
    return nullptr;
}
