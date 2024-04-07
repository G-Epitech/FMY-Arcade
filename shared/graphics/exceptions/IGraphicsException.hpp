/*
** EPITECH PROJECT, 2024
** arcade-shared
** File description:
** IGraphicsException.hpp
*/

#pragma once

#include <exception>

namespace shared::graphics::exceptions {
    class IGraphicsException;
}

/**
 * @brief Interface for the graphics exception object
 * 
 */
class shared::graphics::exceptions::IGraphicsException: public std::exception {
public:
    /**
     * @brief Get error location
     * @return String containing error location
     */
    virtual const char *where() const noexcept = 0;
};
