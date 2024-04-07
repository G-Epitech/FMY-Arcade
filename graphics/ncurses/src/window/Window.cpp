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

using namespace arcade::graphics::ncurses::window;
using namespace arcade::graphics::common::exceptions;

const Vector2u Window::tileSize = { 35, 35 };

Window::Window(const IWindow::WindowInitProps &props):
    _size(props.size),
    _initialSize(0, 0),
    _renderer(*this),
    _eventsHandler(*this),
    _window(nullptr, &delwin)
{
    _mode = props.mode;
    _fps = props.fps;
    _initialSize = _size;
    _isOpen = true;
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    mousemask(ALL_MOUSE_EVENTS, NULL);
    curs_set(0);
    _window = std::unique_ptr<WINDOW, decltype(&delwin)>(newwin(_size.y, _size.x, 0, 0), &delwin);
}

Window::~Window()
{
    wclear(stdscr);
    close();
    endwin();
}

std::unique_ptr<WINDOW, decltype(&delwin)> &Window::getWindow()
{
    return _window;
}

void Window::setTitle(const std::string &title) {
    _title = title;
}

void Window::setSize(shared::types::Vector2u size) {
    _size = size;
}

shared::types::Vector2u Window::getSize() const {
    return _size;
}

void Window::setFramerateLimit(unsigned int fps) {
    _fps = fps;
}

unsigned int Window::getFramerateLimit() const {
    return _fps;
}

void Window::setMode(IWindow::WindowMode mode) {}

Window::WindowMode Window::getMode() const {
    return _mode;
}

bool Window::isOpen() const {
    return _isOpen;
}

void Window::setIcon(const std::string &path) {}

void Window::render(const shared::graphics::TextureProps &props) {
    _renderer.render(props);
}

void Window::render(const shared::graphics::TextProps &props) {
    _renderer.render(props);
}

void Window::clear() {
    wclear(_window.get());
}

void Window::display() {
    for (auto &line : map) {
        for (auto &c : line.second) {
            mvwprintw(_window.get(), line.first, c.first, &c.second);
        }
    }
    wrefresh(_window.get());
}

void Window::close() {
    if (_window) {
        wclear(_window.get());
        wrefresh(_window.get());
    }
    _isOpen = false;
    _window.reset();
}

std::vector<EventPtr> Window::getEvents() {
    return _eventsHandler.handleEvents();
}

void Window::onResize() {}
