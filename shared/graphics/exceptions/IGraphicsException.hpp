/*
** EPITECH PROJECT, 2024
** arcade-shared
** File description:
** IGraphicsException.hpp
*/

#pragma once

#include <string>

namespace shared::graphics::exceptions {
    class IGraphicsException;
}

class shared::graphics::exceptions::IGraphicsException {
public:
    virtual ~IGraphicsException() = default;

    /**
     * @brief Get error details
     * @return String containing error details
     */
    virtual const std::string &what() const noexcept = 0;

    /**
     * @brief Get error location
     * @return String containing error location
     */
    virtual const std::string &where() const noexcept = 0;
};
