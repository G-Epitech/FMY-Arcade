/*
** EPITECH PROJECT, 2024
** arcade-shared
** File description:
** ITextureException.hpp
*/

#pragma once

#include "IGraphicsException.hpp"

namespace shared::graphics::exceptions {
    class ITextureException;
}

class shared::graphics::exceptions::ITextureException : public virtual IGraphicsException {
public:
    virtual ~ITextureException() = default;
};
