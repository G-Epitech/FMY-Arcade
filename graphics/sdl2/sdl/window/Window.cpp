/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Window.cpp
*/

#include "Window.hpp"
#include "sdl/exception/Exception.hpp"

using namespace sdl;

Window::Window(): _renderer(*this) {
    _window = nullptr;
}

Window &Window::create(
    const std::string &title,
    const Vector2i &position,
    const Vector2i &size,
    Uint32 flags
) {
    _window = SDL_CreateWindow(
        title.c_str(),
        position.x,
        position.y,
        size.x,
        size.y,
        flags
    );
    if (!_window)
        throw SDLException("Failed to create window");
    _renderer.create();
    return *this;
}

SDL_Window *Window::operator()() const {
    return _window;
}

Window::~Window() {
    if (_window)
        SDL_DestroyWindow(_window);
}

SDL_Window *Window::_safeWindow() const {
    if (!_window)
        throw SDLException("Window is not created");
    return _window;
}

void Window::setTitle(const std::string &title) {
    SDL_SetWindowTitle(_safeWindow(), title.c_str());
}

void Window::setSize(Vector2i size) {
    SDL_SetWindowSize(_safeWindow(), size.x, size.y);
}

Vector2i Window::getSize() const {
    Vector2i size(0, 0);

    SDL_GetWindowSize(_safeWindow(), &size.x, &size.y);
    return size;
}

void Window::setFullscreen(Uint32 flags) {
    SDL_SetWindowFullscreen(_safeWindow(), flags);
}

Uint32 Window::getFlags() const {
    return SDL_GetWindowFlags(_safeWindow());
}

void Window::setIcon(const std::string &path) {
    _icon.load(path);
    SDL_SetWindowIcon(_safeWindow(), _icon());
}

Renderer &Window::getRenderer() {
    return _renderer;
}

bool Window::pollEvent(Event &event) {
    return SDL_PollEvent(&event);
}
