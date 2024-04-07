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

/**
 * @brief Interface for the window exception object
 * 
 */
class shared::graphics::exceptions::IWindowException : public virtual IGraphicsException {
public:
    virtual ~IWindowException() = default;
};
