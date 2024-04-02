/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** SoundException.hpp
*/

#pragma once

#include "GraphicsException.hpp"
#include "shared/graphics/exceptions/ISoundException.hpp"

using namespace shared::graphics::exceptions;

namespace arcade::graphics::common::exceptions {
    class SoundException;
}

class arcade::graphics::common::exceptions::SoundException: public GraphicsException,  public ISoundException {
public:
    using GraphicsException::GraphicsException;
};
