/*
** EPITECH PROJECT, 2024
** shared-arcade
** File description:
** Vector
*/

#pragma once

namespace shared::types {
    template <typename T>
    struct Vector;

    typedef struct Vector<int> Vector2i;
    typedef struct Vector<float> Vector2f;
    typedef struct Vector<unsigned int> Vector2u;
}

/// @brief Vector type
/// @tparam T Type of the vector
template <typename T>
struct shared::types::Vector {
    /**
     * @brief Construct a new Vector object
     * 
     * @param x X value
     * @param y Y value
     */
    Vector(T x, T y) : x(x), y(y){};

    /**
     * @brief X value
     * In this Graphical Project, it can be refer as :
     * - Width
     * - Longitude
     */
    T x;

    /**
     * @brief Y value
     * In this Graphical Project, it can be refer as :
     * - Height
     * - Latitude
     */
    T y;
};
