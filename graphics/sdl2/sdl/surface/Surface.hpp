/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Image.hpp
*/

#pragma once

#include <SDL2/SDL_image.h>
#include <string>
#include "shared/types/Vector.hpp"

namespace sdl {
    using namespace shared::types;
    class Surface;
    class Renderer;
    class Texture;
}

class sdl::Surface {
public:
    Surface();
    Surface(const Surface &other);
    explicit Surface(SDL_Surface *surface);
    explicit Surface(const std::string &path);
    ~Surface();

    /**
     * @brief Load an image from a file
     * @param path Path to the image file
     * @return Loading success status
     */
    bool load(const std::string &path);
    /**
     * @brief Get the inner SDL surface
     * @return SDL surface pointer
     */
    SDL_Surface *operator()() const;

    /**
     * @brief Get the size of the surface
     * @return Size of the surface
     */
    Vector2i getSize() const;

    /**
     * @brief Convert the surface to a texture
     * @param renderer Renderer to create the texture
     * @return Created texture
     */
    Texture toTexture(Renderer &renderer) const;

private:
    SDL_Surface *_surface;
};
