/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Loader
*/

#include "Loader.hpp"

Loader::Loader() {
    this->_dir = nullptr;
}

Loader::~Loader() {
    if (this->_dir)
        closedir(this->_dir);
}

shared::types::LibraryType Loader::_getLibraryGetter(const std::string &filepath) {
    shared::types::LibraryTypeGetter getter = nullptr;

    getter = this->_dlLoader.getFunction<shared::types::LibraryTypeGetter>(SHARED_STRINGIFY(SHARED_LIBRARY_TYPE_GETTER_NAME));
    return getter();
}

void Loader::_loadGameLibrary(const std::string &filepath) {
    shared::types::GameProviderGetter game = nullptr;

    game = this->_dlLoader.getFunction<shared::types::GameProviderGetter>(SHARED_STRINGIFY(SHARED_GAME_PROVIDER_GETTER_NAME));
    this->_gamesLibraries.push_back(std::unique_ptr<shared::games::IGameProvider>(game()));
}

void Loader::_loadGraphicsLibrary(const std::string &filepath) {
    shared::types::GraphicsProviderGetter graphics = nullptr;

    graphics = this->_dlLoader.getFunction<shared::types::GraphicsProviderGetter>(SHARED_STRINGIFY(SHARED_GRAPHICS_PROVIDER_GETTER_NAME));
    this->_graphicsLibraries.push_back(std::unique_ptr<shared::graphics::IGraphicsProvider>(graphics()));
}

void Loader::registerLibrary(const std::string &filepath) {
    shared::types::LibraryType type;

    this->_dlLoader.openLibrary(filepath);
    type = this->_getLibraryGetter(filepath);
    if (type == shared::types::LibraryType::GAME)
        this->_loadGameLibrary(filepath);
    else if (type == shared::types::LibraryType::GRAPHIC)
        this->_loadGraphicsLibrary(filepath);
    else
        throw ArcadeError(filepath + ": Unknown library type!");
}

void Loader::loadLibraries(std::string path) {
    struct dirent *ent;

    if (this->_dir)
        closedir(this->_dir);
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
}

const GameProviders &Loader::getGamesLibraries() const {
    return this->_gamesLibraries;
}

const GraphicsProviders &Loader::getGraphicsLibraries() const {
    return this->_graphicsLibraries;
}
