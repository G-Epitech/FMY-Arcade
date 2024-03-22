/*
** EPITECH PROJECT, 2024
** shared-arcade
** File description:
** Vector
*/

#pragma once

namespace shared::types
{
  template <typename T>
  struct Vector;

  typedef struct Vector<int> Vector2i;
  typedef struct Vector<float> Vector2f;
  typedef struct Vector<unsigned int> Vector2u;
}

template <typename T>
struct shared::types::Vector
{
  Vector(T x, T y) : x(x), y(y){};

  T x;
  T y;
};
