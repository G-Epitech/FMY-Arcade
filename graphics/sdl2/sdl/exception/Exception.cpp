/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Exception.cpp
*/

#include "Exception.hpp"

#include <utility>

using namespace sdl;

SDLException::SDLException(std::string message) : _message(std::move(message)) {
}


const char *SDLException::what() const noexcept {
    return _message.c_str();
}
