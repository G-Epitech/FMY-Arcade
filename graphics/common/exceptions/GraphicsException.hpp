/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** GraphicsException.hpp
*/

#pragma once

#include <string>
#include "shared/graphics/exceptions/IGraphicsException.hpp"

using namespace shared::graphics::exceptions;

namespace arcade::graphics::common::exceptions {
    class GraphicsException;
}

class arcade::graphics::common::exceptions::GraphicsException : public virtual IGraphicsException {
public:
    GraphicsException(const std::string &message, const std::string &where);
    ~GraphicsException() override = default;

    const char *what() const noexcept override;

    const char *where() const noexcept override;

protected:
    std::string _message;
    std::string _where;
};
