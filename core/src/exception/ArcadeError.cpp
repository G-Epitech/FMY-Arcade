/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** ArcadeError
*/

#include "ArcadeError.hpp"

ArcadeError::ArcadeError(std::string const &message) : _message(message) {}

const char *ArcadeError::what() const noexcept {
    return this->_message.c_str();
}
