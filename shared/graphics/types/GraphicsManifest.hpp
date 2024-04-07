/*
** EPITECH PROJECT, 2024
** shared-arcade
** File description:
** GameManifest
*/

#pragma once
#include <string>
#include <vector>

namespace shared::graphics
{
    /// @brief Author of the graphics library
    typedef struct {
        /// @brief Name of the author
        std::string name;
        /// @brief Public contact email
        std::string email;
        /// @brief Website of the author (`github`, `gitlab`, etc.)
        std::string website;
    } Author;

    /// @brief Graphics library manifest
    typedef struct {
        /// @brief Name of the graphics library
        const std::string name;
        /// @brief Description of the graphics library
        const std::string description;
        /// @brief Version of the graphics library
        const std::string version;
        /// @brief List of authors of the graphics library
        const std::vector<Author> authors;
    } GraphicsManifest;
}
