/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** FontException.hpp
*/

#pragma once

#include "GraphicsException.hpp"
#include "shared/graphics/exceptions/IFontException.hpp"

using namespace shared::graphics::exceptions;

namespace arcade::graphics::common::exceptions {
    class FontException;
}

class arcade::graphics::common::exceptions::FontException: public GraphicsException,  public IFontException {
public:
    using GraphicsException::GraphicsException;
};
