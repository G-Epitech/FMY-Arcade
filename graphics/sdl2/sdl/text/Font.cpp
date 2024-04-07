/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Font.cpp
*/

#include <iostream>
#include "Font.hpp"
#include "sdl/exception/Exception.hpp"

using namespace sdl;

Font::Font() {
    _font = nullptr;
}

Font::Font(const std::string &path, int ptSize): Font() {
    if (!load(path, ptSize))
        throw SDLException("Failed to load font");
}

bool Font::load(const std::string &path, int ptSize) {
    static bool init = false;
    if (!init) {
        if (TTF_Init() == -1)
            throw SDLException("Failed to init TTF");
        init = true;
    }
    if (_font)
        TTF_CloseFont(_font);
    _font = TTF_OpenFont(path.c_str(), ptSize);
    return _font != nullptr;
}

Font::~Font() {
    if (_font)
        TTF_CloseFont(_font);
    _font = nullptr;
}

TTF_Font *Font::_safeFont() const {
    if (!_font)
        throw SDLException("Font is not loaded");
    return _font;
}

TTF_Font *Font::operator()() const {
    return _font;
}

void Font::setSize(unsigned int ptSize) {
    if (TTF_SetFontSize(_safeFont(), static_cast<int>(ptSize)) == -1)
        throw SDLException("Failed to set font size");
}

Surface Font::renderText(const std::string &text, unsigned int fontSize, Color color) {
    SDL_Surface *surface;

    this->setSize(fontSize);
    surface = TTF_RenderText_Blended(_safeFont(), text.c_str(), color());

    if (!surface)
        throw SDLException("Failed to render text");
    return Surface(surface);
}
