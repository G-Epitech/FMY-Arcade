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

void DLLoader::registerLibrary(const std::string &path) {
    void *handle = dlopen(path.c_str(), RTLD_LAZY);
    shared::types::LibraryTypeGetter getter;
    shared::types::LibraryType type;
    shared::types::GameProvider game;
    shared::types::GraphicsProvider graphics;

    std::cout << path << std::endl;
    if (!handle)
        throw ArcadeError("Cannot load library: " + path);
    getter = reinterpret_cast<shared::types::LibraryTypeGetter>(dlsym(handle, SHARED_STRINGIFY(SHARED_LIBRARY_TYPE_GETTER_NAME)));
    if (!getter) {
        dlclose(handle);
        throw ArcadeError("Cannot find getter in library: " + path);
    }
    type = getter();
    if (type == shared::types::LibraryType::GAME) {
        game = reinterpret_cast<shared::types::GameProvider>(dlsym(handle, SHARED_STRINGIFY(SHARED_GAME_PROVIDER_LOADER_NAME)));
        if (!game) {
            dlclose(handle);
            throw ArcadeError("Cannot find game provider in library: " + path);
        }
        this->_gamesLibraries.push_back(game());
    }
    if (type == shared::types::LibraryType::GRAPHIC) {
        graphics = reinterpret_cast<shared::types::GraphicsProvider>(dlsym(handle, SHARED_STRINGIFY(SHARED_GRAPHICS_PROVIDER_LOADER_NAME)));
        if (!graphics) {
            dlclose(handle);
            throw ArcadeError("Cannot find graphics provider in library: " + path);
        }
        this->_graphicsLibraries.push_back(graphics());
    }
}

void DLLoader::loadLibraries(std::string path) {
    DIR *dir;
    struct dirent *ent;

    std::cout << path << std::endl;
    dir = opendir(path.c_str());
    if (!dir)
        return;
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

LoaderGamesProvider DLLoader::getGamesLibraries() const {
    return this->_gamesLibraries;
}

LoaderGraphicsProvider DLLoader::getGraphicsLibraries() const {
    return this->_graphicsLibraries;
}
