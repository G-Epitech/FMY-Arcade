/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** TextureException.hpp
*/

#pragma once

#include "GraphicsException.hpp"
#include "shared/graphics/exceptions/ITextureException.hpp"

using namespace shared::graphics::exceptions;

namespace arcade::graphics::common::exceptions {
    class TextureException;
}

class arcade::graphics::common::exceptions::TextureException: public GraphicsException,  public ITextureException {
public:
    using GraphicsException::GraphicsException;
};
