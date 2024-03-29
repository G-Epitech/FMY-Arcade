/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Loader
*/

#pragma once

#include <dirent.h>
#include "types/Providers.hpp"
#include "utils/DLLoader/DLLoader.hpp"

class Loader {
  public:

    /**
     * @brief Construct a new Loader object
     */
    Loader();

    /**
     * @brief Destroy the Loader object
     */
    ~Loader();

    /**
     * @brief Register a library
     * @param path std::string
     */
    void registerLibrary(const std::string &filepath);

    /**
     * @brief Load all libraries in the given folder path
     * @param path std::string
     */
    void loadLibraries(std::string path);

    /**
     * @brief Get all games libraries
     * @return Loaded games libraries
     */
    const GameProviders &getGamesLibraries() const;

    /**
     * @brief Get all graphics libraries
     * @return Loaded graphics libraries
     */
    const GraphicsProviders &getGraphicsLibraries() const;

  private:
    DLLoader _dlLoader;
    const std::string _path;
    GameProviders _gamesLibraries;
    GraphicsProviders _graphicsLibraries;

    /**
     * @brief Get the Library Getter object
     * @param filepath file path of the library
     * @return getter function
     */
    shared::types::LibraryType _getLibraryGetter(const std::string &filepath);

    /**
     * @brief Load a game library
     * @param filepath file path of the library
     */
    void _loadGameLibrary(const std::string &filepath);

    /**
     * @brief Load a graphics library
     * @param filepath file path of the library
     */
    void _loadGraphicsLibrary(const std::string &filepath);

    /**
     * @brief Throw an error when loading a library
     * @param e exception
     */
    void _throwError(std::exception const &e);
};
