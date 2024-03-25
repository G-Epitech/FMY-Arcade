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
  typedef struct
  {
    std::string name;    // Name of the author
    std::string email;   // Public contact email
    std::string website; // Website of the author (`github`, `gitlab`, etc.)
  } Author;

  typedef struct
  {
    const std::string name;            // Name of the graphics library
    const std::string description;     // Description of the library
    const std::string version;         // Version of the library
    const std::vector<Author> authors; // Authors
  } GraphicsManifest;
}
