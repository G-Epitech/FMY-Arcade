/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** DLLoader
*/

#pragma once

#include <iostream>
#include "types/Providers.hpp"

class DLLoader {
  public:

    /**
     * @brief Register a library
     * @param path std::string
     */
    void registerLibrary(const std::string &path);

    /**
     * @brief Load all libraries in the given folder path
     * @param path std::string
     */
    void loadLibraries(std::string path);

    /**
     * @brief Get all games libraries
     * @return Loaded games libraries
     */
    LoaderGamesProvider getGamesLibraries() const;

    /**
     * @brief Get all graphics libraries
     * @return Loaded graphics libraries
     */
    LoaderGraphicsProvider getGraphicsLibraries() const;

  private:
    const std::string _path;
    LoaderGamesProvider _gamesLibraries;
    LoaderGraphicsProvider _graphicsLibraries;
};
