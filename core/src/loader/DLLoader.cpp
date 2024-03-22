/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** DLLoader
*/

#include <dlfcn.h>
#include <dirent.h>
#include <memory.h>
#include <iostream>
#include "DLLoader.hpp"
#include "exception/ArcadeError.hpp"

shared::types::LibraryType DLLoader::_getLibraryGetter(const std::string &filepath, void *handle) {
    shared::types::LibraryTypeGetter getter = nullptr;

    getter = reinterpret_cast<shared::types::LibraryTypeGetter>(dlsym(handle, SHARED_STRINGIFY(SHARED_LIBRARY_TYPE_GETTER_NAME)));
    if (!getter)
        throw ArcadeError("Cannot find library type getter in library: " + filepath);
    return getter();
}

void DLLoader::_loadGameLibrary(const std::string &filepath, void *handle) {
    shared::types::GameProvider game = nullptr;

    game = reinterpret_cast<shared::types::GameProvider>(dlsym(handle, SHARED_STRINGIFY(SHARED_GAME_PROVIDER_LOADER_NAME)));
    if (!game)
        throw ArcadeError("Cannot find game provider in library: " + filepath);
    this->_gamesLibraries.push_back(game());
}

void DLLoader::_loadGraphicsLibrary(const std::string &filepath, void *handle) {
    shared::types::GraphicsProvider graphics = nullptr;

    graphics = reinterpret_cast<shared::types::GraphicsProvider>(dlsym(handle, SHARED_STRINGIFY(SHARED_GRAPHICS_PROVIDER_LOADER_NAME)));
    if (!graphics)
        throw ArcadeError("Cannot find graphics provider in library: " + filepath);
    this->_graphicsLibraries.push_back(graphics());
}

void DLLoader::registerLibrary(const std::string &filepath) {
    void *handle = dlopen(filepath.c_str(), RTLD_LAZY);
    shared::types::LibraryType type;

    if (!handle)
        throw ArcadeError("Cannot load library: " + filepath);
    type = this->_getLibraryGetter(filepath, handle);
    if (type == shared::types::LibraryType::GAME)
        this->_loadGameLibrary(filepath, handle);
    else if (type == shared::types::LibraryType::GRAPHIC)
        this->_loadGraphicsLibrary(filepath, handle);
    else
        throw ArcadeError("Unknown library type: " + filepath);
}

void DLLoader::loadLibraries(std::string path) {
    DIR *dir;
    struct dirent *ent;

    dir = opendir(path.c_str());
    if (!dir)
        throw ArcadeError("Cannot open directory: " + path);
    ent = readdir(dir);
    while (ent) {
        if (ent->d_name[0] == '.') {
            ent = readdir(dir);
            continue;
        }
        this->registerLibrary(path + "/" + ent->d_name);
        ent = readdir(dir);
    }
    closedir(dir);
}

const GameProviders &DLLoader::getGamesLibraries() const {
    return this->_gamesLibraries;
}

const GraphicsProviders &DLLoader::getGraphicsLibraries() const {
    return this->_graphicsLibraries;
}
