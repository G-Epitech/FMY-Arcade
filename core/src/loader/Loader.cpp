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

Loader::~Loader() {
    this->_gamesLibraries.clear();
    this->_graphicsLibraries.clear();
}

shared::types::LibraryType Loader::_getLibraryGetter(const std::string &filepath, std::shared_ptr<DLLoader> dlLoader) {
    shared::types::LibraryTypeGetter getter = nullptr;

    getter = dlLoader->loadSymbol<shared::types::LibraryTypeGetter>(SHARED_STRINGIFY(SHARED_LIBRARY_TYPE_GETTER_NAME));
    return getter();
}

void Loader::_loadGameLibrary(const std::string &filepath, std::shared_ptr<DLLoader> dlLoader) {
    shared::types::GameProviderGetter game = nullptr;

    game = dlLoader->loadSymbol<shared::types::GameProviderGetter>(SHARED_STRINGIFY(SHARED_GAME_PROVIDER_GETTER_NAME));
    this->_gamesLibraries.insert({filepath, std::shared_ptr<shared::games::IGameProvider>(game())});
    this->_libraries.push_back(dlLoader);
}

void Loader::_loadGraphicsLibrary(const std::string &filepath, std::shared_ptr<DLLoader> dlLoader) {
    shared::types::GraphicsProviderGetter graphics = nullptr;

    graphics = dlLoader->loadSymbol<shared::types::GraphicsProviderGetter>(SHARED_STRINGIFY(SHARED_GRAPHICS_PROVIDER_GETTER_NAME));
    this->_graphicsLibraries.insert({filepath, std::shared_ptr<shared::graphics::IGraphicsProvider>(graphics())});
    this->_libraries.push_back(dlLoader);
}

void Loader::registerLibrary(const std::string &filepath) {
    shared::types::LibraryType type;
    std::shared_ptr<DLLoader> dlLoader = DLLoader::open(filepath);

    type = this->_getLibraryGetter(filepath, dlLoader);
    if (type == shared::types::LibraryType::GAME)
        this->_loadGameLibrary(filepath, dlLoader);
    else if (type == shared::types::LibraryType::GRAPHIC)
        this->_loadGraphicsLibrary(filepath, dlLoader);
    else
        throw ArcadeError(filepath + ": Unknown library type!");
}

void Loader::loadLibraries(std::string path) {
    for (const auto &entry : std::filesystem::directory_iterator(path)) {
        if (entry.is_regular_file())
            this->registerLibrary(entry.path());
    }
}

GameProviders &Loader::getGamesLibraries() {
    return this->_gamesLibraries;
}

GraphicsProviders &Loader::getGraphicsLibraries() {
    return this->_graphicsLibraries;
}
