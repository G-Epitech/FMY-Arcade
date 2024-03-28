/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** GraphicsException.hpp
*/

#pragma once

#include "shared/graphics/exceptions/IGraphicsException.hpp"

using namespace shared::graphics::exceptions;

namespace arcade::graphics::common::exceptions {
    class GraphicsException;
}

class arcade::graphics::common::exceptions::GraphicsException : public IGraphicsException {
public:
    GraphicsException(const std::string &message, const std::string &where);
    ~GraphicsException() override = default;

    const std::string &what() const noexcept override;

    const std::string &where() const noexcept override;

protected:
    std::string _message;
    std::string _where;
};
