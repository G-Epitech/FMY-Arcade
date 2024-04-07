/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Window.hpp
*/

#pragma once

#include <SDL2/SDL.h>
#include <string>
#include "shared/types/Vector.hpp"
#include "sdl/renderer/Renderer.hpp"
#include "sdl/surface/Surface.hpp"
#include "sdl/types/Event.hpp"

namespace sdl {
    using namespace shared::types;

    class Window;
}

class sdl::Window {
public:
    Window();
    ~Window();

    /**
     * @brief Create a window
     * @param title Title of the window
     * @param position Position of the window
     * @param size Size of the window
     */
    Window &create(
        const std::string &title,
        const Vector2i &position,
        const Vector2i &size,
        Uint32 flags = SDL_WINDOW_SHOWN
    );

    /**
     * @brief Close the window
     *
     */
    void close();

    /**
     * @brief Get the window
     * @return SDL_Window
     */
    SDL_Window *operator()() const;

    /**
     * @brief Set the title of the window
     * @param title Title
     */
    void setTitle(const std::string &title);

    /**
     * @brief Set the size of the window
     * @param size Size
     */
    void setSize(Vector2i size);

    /**
     * @brief Get the size of the window
     * @return Size
     */
    Vector2i getSize() const;

    /**
     * @brief Set the fullscreen mode
     * @param fullscreen Fullscreen
     */
    void setFullscreen(Uint32 flags);

    /**
     * @brief Get the flags of the window
     * @return Flags
     */
    Uint32 getFlags() const;

    /**
     * @brief Get the renderer
     * @return Renderer
     */
    Renderer &getRenderer();

    /**
     * @brief Set the icon of the window
     * @param path Path of icon to set
     */
    void setIcon(const std::string &path);

    /**
     * @brief Poll an event
     * @param event Event to fill
     * @return Event status
     */
    static bool pollEvent(Event &event);

private:
    /**
     * @brief Get the window safely and throw an exception if it's not created
     * @return Window pointer
     */
    SDL_Window *_safeWindow() const;

    SDL_Window  *_window;
    Surface     _icon;
    Renderer    _renderer;
};
