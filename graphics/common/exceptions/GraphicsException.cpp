/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** GraphicsException.cpp
*/

#include "GraphicsException.hpp"

using namespace arcade::graphics::common::exceptions;

GraphicsException::GraphicsException(const std::string &message, const std::string &where)
{
    this->_message = message;
    this->_where = where;
}

const std::string &GraphicsException::what() const noexcept {
    return this->_message;
}

const std::string &GraphicsException::where() const noexcept {
    return this->_where;
}
