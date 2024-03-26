/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** DLLoader
*/

#include <dlfcn.h>
#include <memory.h>
#include <iostream>
#include "DLLoader.hpp"
#include "exception/ArcadeError.hpp"

void DLLoader::_loadError(void *handle) {
    std::string error = dlerror();

    if (this->_dir)
        closedir(this->_dir);
    if (handle)
        dlclose(handle);
    throw ArcadeError(error.length() ? error : "Unknown error while loading library");
}

shared::types::LibraryType DLLoader::_getLibraryGetter(const std::string &filepath, void *handle) {
    shared::types::LibraryTypeGetter getter = nullptr;

    getter = reinterpret_cast<shared::types::LibraryTypeGetter>(dlsym(handle, SHARED_STRINGIFY(SHARED_LIBRARY_TYPE_GETTER_NAME)));
    if (!getter)
        this->_loadError(handle);
    return getter();
}

void DLLoader::_loadGameLibrary(const std::string &filepath, void *handle) {
    shared::types::GameProvider game = nullptr;

    game = reinterpret_cast<shared::types::GameProvider>(dlsym(handle, SHARED_STRINGIFY(SHARED_GAME_PROVIDER_LOADER_NAME)));
    if (!game)
        this->_loadError(handle);
    this->_gamesLibraries.push_back(game());
}

void DLLoader::_loadGraphicsLibrary(const std::string &filepath, void *handle) {
    shared::types::GraphicsProvider graphics = nullptr;

    graphics = reinterpret_cast<shared::types::GraphicsProvider>(dlsym(handle, SHARED_STRINGIFY(SHARED_GRAPHICS_PROVIDER_LOADER_NAME)));
    if (!graphics)
        this->_loadError(handle);
    this->_graphicsLibraries.push_back(graphics());
}

void DLLoader::registerLibrary(const std::string &filepath) {
    void *handle = dlopen(filepath.c_str(), RTLD_LAZY);;
    shared::types::LibraryType type;

    if (!handle)
        this->_loadError(handle);
    dlerror();
    type = this->_getLibraryGetter(filepath, handle);
    if (type == shared::types::LibraryType::GAME)
        return this->_loadGameLibrary(filepath, handle);
    else if (type == shared::types::LibraryType::GRAPHIC)
        return this->_loadGraphicsLibrary(filepath, handle);
    dlclose(handle);
    if (this->_dir)
        closedir(this->_dir);
    throw ArcadeError(filepath + ": Unknown library type!");
}

void DLLoader::loadLibraries(std::string path) {
    struct dirent *ent;

    this->_dir = opendir(path.c_str());
    if (!this->_dir)
        throw ArcadeError("Cannot open directory: " + path);
    ent = readdir(this->_dir);
    while (ent) {
        if (ent->d_name[0] == '.') {
            ent = readdir(this->_dir);
            continue;
        }
        this->registerLibrary(path + "/" + ent->d_name);
        ent = readdir(this->_dir);
    }
    closedir(this->_dir);
}

const GameProviders &DLLoader::getGamesLibraries() const {
    return this->_gamesLibraries;
}

const GraphicsProviders &DLLoader::getGraphicsLibraries() const {
    return this->_graphicsLibraries;
}
