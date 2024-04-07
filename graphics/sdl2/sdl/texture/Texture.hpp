/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Texture.hpp
*/

#pragma once

#include <SDL2/SDL.h>
#include "sdl/surface/Surface.hpp"

namespace sdl {
    class Texture;
    class Renderer;
}

class sdl::Texture {
public:
    Texture();
    ~Texture();

    /**
     * @brief Construct a new Texture object from an existing SDL2 texture
     * @param texture SDL2 texture
     */
    explicit Texture(SDL_Texture *texture);

    /**
     * @brief Construct a new Texture object from another texture
     * @param texture Texture to copy
     */
    Texture &operator=(Texture &&texture) noexcept;

    /**
     * @brief Construct a new Texture object from a surface
     * @param renderer Renderer to create the texture
     * @param surface Surface to create the texture
     */
    explicit Texture(Renderer &renderer, Surface &surface);

    /**
     * @brief Get the inner SDL2 texture
     * @return Reference to the inner SDL2 texture
     */
    SDL_Texture *operator()() const;

    /**
     * @brief Get the size of the texture
     * @return Texture size
     */
    Vector2i getSize() const;

private:
    SDL_Texture *_texture;
};
