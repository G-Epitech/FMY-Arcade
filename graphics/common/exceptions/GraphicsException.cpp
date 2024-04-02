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

const char *GraphicsException::what() const noexcept {
    return this->_message.c_str();
}

const char *GraphicsException::where() const noexcept {
    return this->_where.c_str();
}
