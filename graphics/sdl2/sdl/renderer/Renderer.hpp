/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Renderer.hpp
*/

#pragma once

#include <SDL2/SDL.h>
#include <memory>
#include "sdl/types/Color.hpp"
#include "sdl/types/Rect.hpp"
#include "sdl/text/Text.hpp"

namespace sdl {
    class Renderer;
    class Window;
    class Texture;
}

class sdl::Renderer {
public:
    explicit Renderer(const Window &window);
    ~Renderer();

    /**
     * @brief Create a renderer for current window
     * @param window Window
     * @return Renderer
     */
    Renderer& create();

    /**
     * @brief Get the renderer
     * @return SDL_Renderer
     */
    SDL_Renderer *operator()() const;

    /**
     * @brief Draw a color on the screen
     * @param color Color to draw
     */
    void drawColor(Color color);

    /**
     * @brief Copy a texture to the screen
     * @param texture Texture to copy
     * @param srcRect Source rectangle
     * @param destRect Source rectangle
     */
    void copy(Texture &texture, std::unique_ptr<Rect> srcRect, std::unique_ptr<FRect> destRect);

    /**
     * @brief Clear the screen
     */
    void clear();

    /**
     * @brief Present the screen
     */
    void present();

private:
    /**
     * @brief Get the renderer safely or throw an exception if it's null
     * @return Get the renderer
     */
    SDL_Renderer *_safeRenderer();

    SDL_Renderer *_renderer;
    const Window &_window;
};
