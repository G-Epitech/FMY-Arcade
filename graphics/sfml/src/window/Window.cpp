/*
** EPITECH PROJECT, 2024
** Window.cpp
** File description:
** Window class
*/

#include <iostream>
#include "Window.hpp"
#include "EventsHandler.hpp"
#include "common/events/mouse/mouse.hpp"
#include "common/exceptions/WindowException.hpp"

using namespace arcade::graphics::sfml::window;
using namespace arcade::graphics::common::exceptions;

Window::Window(const IWindow::WindowInitProps &props): _renderer(_window, props.size)
{
    auto size = _getInitSize(props.size);
    std::cout << "Size: " << size.x << " " << size.y << std::endl;
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
    (void) size;
    //this->_window->setSize(sf::Vector2u(size.x, size.y));
}

shared::types::Vector2u Window::getSize() const {
    return {12, 12};
    //return shared::types::Vector2u(this->_window->getSize().x, this->_window->getSize().y);
}

void Window::setFramerateLimit(unsigned int fps) {
    _window.setFramerateLimit(fps);
    _fps = fps;
}

unsigned int Window::getFramerateLimit() const {
    return _fps;
}

void Window::setMode(IWindow::WindowMode mode) {
    this->_mode = mode;
    if (mode == FULLSCREEN) {
        _window.create(
            sf::VideoMode(1920, 1080),
            this->_title,
            sf::Style::Fullscreen
        );
    } else {
        _window.create(
            sf::VideoMode(1920, 1080),
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
    std::cout << "Rendering text" << std::endl;
    _renderer.render(props);
}

void Window::clear() {
    _window.clear();
}

void Window::display() {
    sf::RectangleShape rect(sf::Vector2f(_renderer.tileSize.x, _renderer.tileSize.y));
    rect.setOutlineColor(sf::Color::Red);
    rect.setFillColor(sf::Color::Transparent);
    rect.setOutlineThickness(1);
    for (unsigned int i = 0; i < 1920 / _renderer.tileSize.x; i++) {
        for (unsigned int j = 0; j < 1080 / _renderer.tileSize.y; j++) {
            rect.setPosition(i * _renderer.tileSize.x, j * _renderer.tileSize.y);
            _window.draw(rect);
        }
    }
    _window.display();
}

void Window::close() {
    _window.close();
}

std::vector<EventPtr> Window::getEvents() {
    return EventsHandler::handleEvents(*this);
}

Vector2u Window::_getInitSize(const Vector2u &requestedSize) const {
    Vector2u size(1920, 1080);

    if (requestedSize.x * static_cast<unsigned int>(_renderer.tileSize.x) < 1920)
        size.x = requestedSize.x * static_cast<unsigned int>(_renderer.tileSize.x);
    if (requestedSize.y * static_cast<unsigned int>(_renderer.tileSize.y) < 1080)
        size.y = requestedSize.y * static_cast<unsigned int>(_renderer.tileSize.y);
    return size;
}
