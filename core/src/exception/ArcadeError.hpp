/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** ArcadeError
*/

#pragma once

#include <iostream>

class ArcadeError : public std::exception {
  public:
    explicit ArcadeError(std::string const &message);

    const char *what() const noexcept;
  private:
    const std::string _message;
};
