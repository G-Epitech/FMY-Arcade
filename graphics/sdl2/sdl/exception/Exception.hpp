/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Exception.hpp
*/

#pragma once
#include <exception>
#include <string>

namespace sdl {
    class SDLException;
}

class sdl::SDLException: public std::exception {
public:
    explicit SDLException(std::string message);
    ~SDLException() override = default;

    /**
     * @brief Get the exception message
     * @return Message of the exception
     */
    const char *what() const noexcept override;

private:
    const std::string _message;
};
