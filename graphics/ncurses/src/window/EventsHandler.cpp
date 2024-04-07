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

#include <ncurses.h>

using namespace arcade::graphics::ncurses::window;

EventsHandler::EventsHandler(Window &window) : _window(window) {}

std::vector<EventPtr> EventsHandler::handleEvents()
{
    std::vector<EventPtr> events;

    while (true) {
        int event = getch();

        if (event == ERR) {
            break;
        } else {
            auto eventPtr = _handleKeyPressEvent(event);
            if (eventPtr)
                events.push_back(eventPtr);
        }
    }
    return events;
}

EventPtr EventsHandler::_handleKeyPressEvent(int code)
{
    if (code >= 265 && code <= 276)
        return _handleFunctionKey(code);
    if (code >= 258 && code <= 261)
        return _handleArrowKey(code);
    if (code == 263)
        return std::make_shared<KeyPressEvent>(IKeyEvent::KeyType::CHAR, IKeyEvent::KeyCode{.character = '\b'});
    if (code == 330)
        return std::make_shared<WindowCloseEvent>();
    return _handleCharKey(code);
}

EventPtr EventsHandler::_handleFunctionKey(int code)
{
    unsigned char funcCode = code - 265 + 1;

    return std::make_shared<KeyPressEvent>(IKeyEvent::KeyType::FUNC, IKeyEvent::KeyCode{.func = funcCode});
}

EventPtr EventsHandler::_handleArrowKey(int code)
{
    IKeyEvent::ArrowCode arrowCode;

    switch (code) {
        case 259:
            arrowCode = IKeyEvent::ArrowCode::UP;
            break;
        case 258:
            arrowCode = IKeyEvent::ArrowCode::DOWN;
            break;
        case 260:
            arrowCode = IKeyEvent::ArrowCode::LEFT;
            break;
        case 261:
            arrowCode = IKeyEvent::ArrowCode::RIGHT;
            break;
        default:
            return nullptr;
    }
    return std::make_shared<KeyPressEvent>(IKeyEvent::KeyType::ARROW, IKeyEvent::KeyCode{.arrow = arrowCode});
}

EventPtr EventsHandler::_handleCharKey(int code)
{
    return std::make_shared<KeyPressEvent>(IKeyEvent::KeyType::CHAR, IKeyEvent::KeyCode{.character = static_cast<char>(code)});
}
