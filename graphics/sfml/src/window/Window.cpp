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

const Vector2u Window::tileSize = { 12, 12 };

Window::Window(const IWindow::WindowInitProps &props):
    _size(props.size),
    _renderer(*this),
    _eventsHandler(*this)
{
    auto size = getPixelSizeFromTiles(props.size);

    _mode = props.mode;
    _fps = props.fps;
    _window.create(
        sf::VideoMode(size.x, size.y),
        props.title
    );
    Window::setIcon(props.icon);
    _view.setSize(size.x, size.y);
    _view.setCenter(size.x / 2, size.y / 2);
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
    auto real = getPixelSizeFromTiles(size);

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
    _renderer.render(props);
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

Vector2u Window::getPixelSizeFromTiles(const Vector2u &size) {
    auto mode = sf::VideoMode::getDesktopMode();
    Vector2u real(mode.width, mode.height);

    if (size.x * static_cast<unsigned int>(tileSize.x) < mode.width)
        real.x = size.x * static_cast<unsigned int>(tileSize.x);
    if (size.y * static_cast<unsigned int>(tileSize.y) < mode.height)
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

void Window::viewResize(const sf::Event &event) {
    Vector2u orignalPixels = getPixelSizeFromTiles(_size);
    float widht = event.size.width;
    float height = event.size.height;

    _view.setSize(event.size.width, event.size.height);
    _view.setCenter(orignalPixels.x / 2, orignalPixels.y / 2);
    if (widht < height) {
        auto zoom = static_cast<float>(orignalPixels.x) / event.size.width;
        _view.zoom(zoom);
    } else {
        auto zoom = static_cast<float>(orignalPixels.y) / event.size.height;
        _view.zoom(zoom);
    }
    _window.setView(_view);
}
