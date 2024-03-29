/*
** EPITECH PROJECT, 2024
** arcade-shared
** File description:
** IFontException.hpp
*/

#pragma once

#include "IGraphicsException.hpp"

namespace shared::graphics::exceptions {
    class IFontException;
}

class shared::graphics::exceptions::IFontException : public virtual IGraphicsException {
public:
    virtual ~IFontException() = default;
};
