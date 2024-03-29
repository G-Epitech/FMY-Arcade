/*
** EPITECH PROJECT, 2024
** Window.cpp
** File description:
** Window class
*/

#include "Window.hpp"
#include "EventsHandler.hpp"
#include "common/events/mouse/mouse.hpp"
#include "common/exceptions/WindowException.hpp"

using namespace arcade::graphics::sfml::window;
using namespace arcade::graphics::common::exceptions;

Window::Window(const IWindow::WindowInitProps &props):
    _size(props.size),
    _renderer(_window, props.size),
    _eventsHandler(*this)
{
    auto size = _getPixelSizeFromTiles(props.size);

    _mode = props.mode;
    _fps = props.fps;
    _window.create(
        sf::VideoMode(size.x, size.y),
        props.title
    );
    Window::setIcon(props.icon);
}

Window::~Window()
{
    _window.close();
}

sf::RenderWindow &Window::getInnerWindow() noexcept {
    return _window;
}

void Window::setTitle(const std::string &title) {
    _window.setTitle(title);
}

void Window::setSize(shared::types::Vector2u size) {
    auto real = _getPixelSizeFromTiles(size);

    _size = size;
    _window.setSize(sf::Vector2u(real.x, real.y));
}

shared::types::Vector2u Window::getSize() const {
    return _size;
}

void Window::setFramerateLimit(unsigned int fps) {
    _window.setFramerateLimit(fps);
    _fps = fps;
}

unsigned int Window::getFramerateLimit() const {
    return _fps;
}

void Window::setMode(IWindow::WindowMode mode) {
    auto size = _window.getSize();

    this->_mode = mode;
    if (mode == FULLSCREEN) {
        _window.create(
            sf::VideoMode(size.x, size.y),
            this->_title,
            sf::Style::Fullscreen
        );
    } else {
        _window.create(
            sf::VideoMode(size.x, size.y),
            this->_title,
            sf::Style::Default
        );
    }
}

Window::WindowMode Window::getMode() const {
    return _mode;
}

bool Window::isOpen() const {
    return _window.isOpen();
}

void Window::setIcon(const std::string &path) {
    if (path.empty())
        return;
    if (!_icon.loadFromFile(path)) {
        throw WindowException(
            "Failed to load icon at: " + path,
            "Window.setIcon in SFML library"
        );
    }
    _window.setIcon(
        _icon.getSize().x,
        _icon.getSize().y,
        _icon.getPixelsPtr()
    );
}

void Window::render(const shared::graphics::TextureProps &props) {
    (void) props;
}

void Window::render(const shared::graphics::TextProps &props) {
    _renderer.render(props);
}

void Window::clear() {
    _window.clear();
}

void Window::display() {
    _window.display();
}

void Window::close() {
    _window.close();
}

std::vector<EventPtr> Window::getEvents() {
    return _eventsHandler.handleEvents();
}

Vector2u Window::_getPixelSizeFromTiles(const Vector2u &size) const {
    Vector2u real(1920, 1080);

    if (size.x * static_cast<unsigned int>(_renderer.tileSize.x) < 1920)
        real.x = size.x * static_cast<unsigned int>(_renderer.tileSize.x);
    if (size.y * static_cast<unsigned int>(_renderer.tileSize.y) < 1080)
        real.y = size.y * static_cast<unsigned int>(_renderer.tileSize.y);
    return real;
}
