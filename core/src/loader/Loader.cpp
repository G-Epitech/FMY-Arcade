/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Loader
*/

#include <filesystem>
#include "Loader.hpp"
#include "exception/ArcadeError.hpp"

Loader::Loader() {}

Loader::~Loader() {}

shared::types::LibraryType Loader::_getLibraryGetter(const std::string &filepath) {
    shared::types::LibraryTypeGetter getter = nullptr;

    getter = this->_dlLoader.loadSymbol<shared::types::LibraryTypeGetter>(SHARED_STRINGIFY(SHARED_LIBRARY_TYPE_GETTER_NAME));
    return getter();
}

void Loader::_loadGameLibrary(const std::string &filepath) {
    shared::types::GameProviderGetter game = nullptr;

    game = this->_dlLoader.loadSymbol<shared::types::GameProviderGetter>(SHARED_STRINGIFY(SHARED_GAME_PROVIDER_GETTER_NAME));
    this->_gamesLibraries.push_back(std::unique_ptr<shared::games::IGameProvider>(game()));
}

void Loader::_loadGraphicsLibrary(const std::string &filepath) {
    shared::types::GraphicsProviderGetter graphics = nullptr;

    graphics = this->_dlLoader.loadSymbol<shared::types::GraphicsProviderGetter>(SHARED_STRINGIFY(SHARED_GRAPHICS_PROVIDER_GETTER_NAME));
    this->_graphicsLibraries.push_back(std::unique_ptr<shared::graphics::IGraphicsProvider>(graphics()));
}

void Loader::registerLibrary(const std::string &filepath) {
    shared::types::LibraryType type;

    this->_dlLoader.open(filepath);
    type = this->_getLibraryGetter(filepath);
    if (type == shared::types::LibraryType::GAME)
        this->_loadGameLibrary(filepath);
    else if (type == shared::types::LibraryType::GRAPHIC)
        this->_loadGraphicsLibrary(filepath);
    else
        throw ArcadeError(filepath + ": Unknown library type!");
}

void Loader::loadLibraries(std::string path) {
    for (const auto &entry : std::filesystem::directory_iterator(path)) {
        if (entry.is_regular_file() && entry.path().extension() == ".so")
            this->registerLibrary(entry.path());
    }
}

const GameProviders &Loader::getGamesLibraries() const {
    return this->_gamesLibraries;
}

const GraphicsProviders &Loader::getGraphicsLibraries() const {
    return this->_graphicsLibraries;
}
