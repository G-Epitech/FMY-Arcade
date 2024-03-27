/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Loader
*/

#include <dlfcn.h>
#include <memory.h>
#include <iostream>
#include "Loader.hpp"
#include "exception/ArcadeError.hpp"

void Loader::_throwLoadError(void *handle) {
    std::string error = dlerror();

    if (this->_dir)
        closedir(this->_dir);
    if (handle)
        dlclose(handle);
    throw ArcadeError(error.length() ? error : "Unknown error while loading library");
}

shared::types::LibraryType Loader::_getLibraryGetter(const std::string &filepath, void *handle) {
    shared::types::LibraryTypeGetter getter = nullptr;

    getter = reinterpret_cast<shared::types::LibraryTypeGetter>(dlsym(handle, SHARED_STRINGIFY(SHARED_LIBRARY_TYPE_GETTER_NAME)));
    if (!getter)
        this->_throwLoadError(handle);
    return getter();
}

void Loader::_loadGameLibrary(const std::string &filepath, void *handle) {
    shared::types::GameProviderGetter game = nullptr;

    game = reinterpret_cast<shared::types::GameProviderGetter>(dlsym(handle, SHARED_STRINGIFY(SHARED_GAME_PROVIDER_LOADER_NAME)));
    if (!game)
        this->_throwLoadError(handle);
    this->_gamesLibraries.push_back(std::unique_ptr<shared::games::IGameProvider>(game()));
}

void Loader::_loadGraphicsLibrary(const std::string &filepath, void *handle) {
    shared::types::GraphicsProviderGetter graphics = nullptr;

    graphics = reinterpret_cast<shared::types::GraphicsProviderGetter>(dlsym(handle, SHARED_STRINGIFY(SHARED_GRAPHICS_PROVIDER_LOADER_NAME)));
    if (!graphics)
        this->_throwLoadError(handle);
    this->_graphicsLibraries.push_back(std::unique_ptr<shared::graphics::IGraphicsProvider>(graphics()));
}

void Loader::registerLibrary(const std::string &filepath) {
    void *handle = dlopen(filepath.c_str(), RTLD_LAZY);;
    shared::types::LibraryType type;

    if (!handle)
        this->_throwLoadError(handle);
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

void Loader::loadLibraries(std::string path) {
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

const GameProviders &Loader::getGamesLibraries() const {
    return this->_gamesLibraries;
}

const GraphicsProviders &Loader::getGraphicsLibraries() const {
    return this->_graphicsLibraries;
}
