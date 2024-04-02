/*
** EPITECH PROJECT, 2024
** arcade-shared
** File description:
** ISoundException.hpp
*/

#pragma once

#include "IGraphicsException.hpp"

namespace shared::graphics::exceptions {
    class ISoundException;
}

class shared::graphics::exceptions::ISoundException : public virtual IGraphicsException {
public:
    virtual ~ISoundException() = default;
};
