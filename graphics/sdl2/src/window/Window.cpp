/*
** EPITECH PROJECT, 2024
** Window.cpp
** File description:
** Window class
*/

#include "Window.hpp"
#include "EventsHandler.hpp"
#include "graphics/sdl2/sdl/exception/Exception.hpp"
#include "common/events/mouse/mouse.hpp"
#include "common/exceptions/WindowException.hpp"

using namespace arcade::graphics::sdl2::window;
using namespace arcade::graphics::common::exceptions;

const Vector2u Window::tileSize = { 12, 12 };

Window::Window(const IWindow::WindowInitProps &props):
    _size(props.size),
    _renderer(*this),
    _eventsHandler(*this),
    _isOpen(true)
{
    _mode = props.mode;
    _fps = props.fps;
    _initInnerWindow(props);
    Window::setIcon(props.icon);
}

Window::~Window() = default;

sdl::Window &Window::getInnerWindow() noexcept {
    return _window;
}

void Window::setTitle(const std::string &title) {
    _window.setTitle(title);
}

void Window::setSize(shared::types::Vector2u size) {
    auto real = _getPixelSizeFromTiles(size);

    _size = size;
    _window.setSize({
        static_cast<int>(real.x),
        static_cast<int>(real.y)
    });
}

shared::types::Vector2u Window::getSize() const {
    return _size;
}

void Window::setFramerateLimit(unsigned int fps) {
    _fps = fps;
    _window.getRenderer().setFramerateLimit(_fps);
}

unsigned int Window::getFramerateLimit() const {
    return _fps;
}

void Window::setMode(IWindow::WindowMode mode) {
    auto isFullscreen = _window.getFlags() & SDL_WINDOW_FULLSCREEN;

    this->_mode = mode;
    if (mode == FULLSCREEN && !isFullscreen) {
        _window.setFullscreen(SDL_WINDOW_FULLSCREEN);
    } else {
        _window.setFullscreen(0);
    }
}

Window::WindowMode Window::getMode() const {
    return _mode;
}

bool Window::isOpen() const {
    return _isOpen;
}

void Window::setIcon(const std::string &path) {
    if (path.empty())
        return;
    try {
        _window.setIcon(path);
    } catch (const sdl::SDLException &e) {
        throw WindowException(
            "Failed to set icon",
            "setIcon in SDL2 library"
        );
    }
}

void Window::render(const shared::graphics::TextureProps &props) {
    _renderer.render(props);
}

void Window::render(const shared::graphics::TextProps &props) {
    _renderer.render(props);
}

void Window::clear() {
    _window.getRenderer().drawColor(sdl::ColorBlack);
    _window.getRenderer().clear();
}

void Window::display() {
    _window.getRenderer().present();
}

void Window::close() {
    _isOpen = false;
}

std::vector<EventPtr> Window::getEvents() {
    return _eventsHandler.handleEvents();
}

void Window::_initInnerWindow(const shared::graphics::IWindow::WindowInitProps &props) {
    auto size = _getPixelSizeFromTiles(props.size);

    try {
        _window.create(
            props.title,
            { SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED },
            { static_cast<int>(size.x), static_cast<int>(size.y) },
            0
        );
    } catch (const sdl::SDLException &e) {
        throw WindowException(
            "Failed to create window",
            "Window constructor in SDL2 library"
        );
    }
}

Vector2u Window::_getPixelSizeFromTiles(const Vector2u &size) {
    //auto mode = sf::VideoMode::getDesktopMode();
    Vector2u real(1920, 1080);

    if (size.x * static_cast<unsigned int>(tileSize.x) < 1920)
        real.x = size.x * static_cast<unsigned int>(tileSize.x);
    if (size.y * static_cast<unsigned int>(tileSize.y) < 1080)
        real.y = size.y * static_cast<unsigned int>(tileSize.y);
    return real;
}

Vector2i Window::pixelsToTiles(const shared::types::Vector2i &position) const {
    auto realSize = _window.getSize();

    return {
        static_cast<int>(position.x * _size.x / realSize.x),
        static_cast<int>(position.y * _size.y / realSize.y)
    };
}

Vector2i Window::tilesToPixels(const Vector2i &position) const {
    auto realSize = _window.getSize();

    return {
        static_cast<int>(position.x * realSize.x / _size.x),
        static_cast<int>(position.y * realSize.y / _size.y)
    };
}

Vector2i Window::tilesToPixels(const Vector2u &position) const {
    auto realSize = _window.getSize();

    return {
        static_cast<int>(position.x * realSize.x / _size.x),
        static_cast<int>(position.y * realSize.y / _size.y)
    };
}
