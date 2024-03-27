/*
** EPITECH PROJECT, 2024
** Window.cpp
** File description:
** Window class
*/

#include <iostream>
#include "Window.hpp"

using namespace arcade::graphics::sfml;

Window::Window(const IWindow::WindowInitProps &props)
{
    this->_mode = props.mode;
    this->_fps = props.fps;
    this->_window = std::make_unique<sf::RenderWindow>(
        sf::VideoMode(props.size.x, props.size.y),
        props.title
    );
}

Window::~Window()
{
    this->_window->close();
}

void Window::setTitle(const std::string &title) {
    this->_window->setTitle(title);
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
    this->_window->setFramerateLimit(fps);
    this->_fps = fps;
}

unsigned int Window::getFramerateLimit() const {
    return this->_fps;
}

void Window::setMode(IWindow::WindowMode mode) {
    this->_mode = mode;
    if (mode == FULLSCREEN) {
        this->_window->create(
            sf::VideoMode(1920, 1080),
            this->_title,
            sf::Style::Fullscreen
        );
    } else {
        this->_window->create(
            sf::VideoMode(1920, 1080),
            this->_title,
            sf::Style::Default
        );
    }
}

IWindow::WindowMode Window::getMode() const {
    return this->_mode;
}

bool Window::isOpen() const {
    return this->_window->isOpen();
}

void Window::setIcon(const std::string &icon) {
    (void) icon;
}
void Window::render(const TextProps &props) {
    (void) props;
}

void Window::render(const TextureProps &props) {
    (void) props;
}

void Window::clear() {
    this->_window->clear();
}

void Window::display() {
    this->_window->display();
}

void Window::close() {
    this->_window->close();
}

std::vector<events::EventPtr> Window::getEvents() {
    sf::Event event{};
    std::vector<events::EventPtr> events;

    while (this->_window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            this->_window->close();
            return events;
        }
        std::cout << "Event received" << std::endl;
    }
    return events;
}
