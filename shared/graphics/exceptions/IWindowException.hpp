/*
** EPITECH PROJECT, 2024
** arcade-shared
** File description:
** IWindowException.hpp
*/

#pragma once

#include "IGraphicsException.hpp"

namespace shared::graphics::exceptions {
    class IWindowException;
}

class shared::graphics::exceptions::IWindowException : public virtual IGraphicsException {
public:
    virtual ~IWindowException() = default;
};
