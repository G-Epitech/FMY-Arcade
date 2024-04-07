/*
** EPITECH PROJECT, 2024
** shared-arcade
** File description:
** GameManifest
*/

#pragma once

#include <string>
#include <vector>

namespace shared::games {

    /// @brief Author of the game
    typedef struct {
        /// @brief Name of the author
        std::string name;
        /// @brief Public contact email
        std::string email;
        /// @brief Website of the author (`github`, `gitlab`, etc.)
        std::string website;
    } Author;

    /// @brief Game manifest
    typedef struct {
        /// @brief Name of the game
        const std::string name;
        /// @brief Description of the game
        const std::string description;
        /// @brief Version of the game
        const std::string version;
        /// @brief List of authors of the game
        const std::vector <Author> authors;
        /// @brief Path of the icon game
        const std::string iconPath;
    } GameManifest;
}
