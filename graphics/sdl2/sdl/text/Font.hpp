/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Font.hpp
*/

#pragma once

#include <string>
#include <memory>
#include <SDL2/SDL_ttf.h>
#include "sdl/surface/Surface.hpp"
#include "sdl/types/Color.hpp"

namespace sdl {
    class Font;
    typedef std::shared_ptr<Font> SharedFont;
}

class sdl::Font {
public:
    Font();
    explicit Font(const std::string &path, int ptSize = 12);
    ~Font();

    /**
     * @brief Load a font from a file
     * @param path Path to the font file
     * @param ptSize Font size
     * @return True if the font was loaded successfully
     * @throw False if the font could not be loaded
     */
    bool load(const std::string &path, int ptSize = 12);

    /**
     * @brief Get inner SDL font pointer
     * @return SDL Font pointer
     */
    TTF_Font *operator()() const;

    /**
     * @brief Set the size of the font
     * @param ptSize Font size
     */
    void setSize(unsigned int ptSize);

    /**
     * @brief Create a surface from a string
     * @param text Text to render
     * @param color Color of the text
     * @return Created surface
     */
    Surface renderText(const std::string &text, unsigned int fontSize, Color color = ColorWhite);

private:
    TTF_Font *_font;

    /**
     * @brief Get the font pointer if is not null or throw an exception
     * @return SDL font pointer
     */
    TTF_Font *_safeFont() const;
};
