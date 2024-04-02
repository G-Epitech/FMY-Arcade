/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** WindowException.hpp
*/

#pragma once

#include "GraphicsException.hpp"
#include "shared/graphics/exceptions/IWindowException.hpp"

using namespace shared::graphics::exceptions;

namespace arcade::graphics::common::exceptions {
    class WindowException;
}

class arcade::graphics::common::exceptions::WindowException: public GraphicsException,  public IWindowException {
public:
    using GraphicsException::GraphicsException;
};
