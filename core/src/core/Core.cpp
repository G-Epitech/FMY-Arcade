/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Core
*/

#include <chrono>
#include <memory.h>
#include "Core.hpp"
#include "shared/games/components/IComponent.hpp"

Core::Core(GameProviders gameProviders, GraphicsProviders graphicsProviders)
{
    this->_gameProviders = gameProviders;
    this->_graphicsProviders = graphicsProviders;
    this->_gameProvider = this->_gameProviders.at(0);
    this->_graphicsProvider = this->_graphicsProviders.at(0);
}

Core::~Core() {}

void Core::_initGame()
{
    this->_game = this->_gameProvider.get()->createInstance();
}

void Core::_initWindow()
{
    auto gameManifest = this->_game.get()->getManifest();
    shared::graphics::IWindow::WindowInitProps windowInitProps {
        this->_game.get()->getSize(),
        shared::graphics::IWindow::WINDOWED,
        this->_game.get()->getFps(),
        gameManifest.name,
        gameManifest.iconPath
    };

    this->_window = this->_graphicsProvider.get()->createWindow(windowInitProps);
}

std::shared_ptr<shared::graphics::ITexture> Core::_getTexture(std::string bin, std::string ascii)
{
    if (this->_textures.find(bin + ascii) == this->_textures.end())
        this->_textures[bin + ascii] = this->_graphicsProvider.get()->createTexture(bin, ascii);
    return this->_textures[bin + ascii];
}

shared::graphics::TextureProps Core::_getTextureEntity(std::shared_ptr<shared::games::components::ITextureComponent> texture)
{
    auto textureProps = texture.get()->getTextureProps();
    shared::graphics::TextureProps entityTextureProps {
        this->_getTexture(textureProps.sources.bin, textureProps.sources.ascii),
        textureProps.sources.binTileSize,
        textureProps.origin,
        texture.get()->getSize(),
        texture.get()->getPosition()
    };

    return entityTextureProps;
}

void Core::_renderEntities()
{
    std::map<unsigned int, std::vector<shared::graphics::TextureProps>> entitiesTextureProps;
    std::map<unsigned int, std::vector<shared::graphics::TextProps>> entitiesTextProps;

    for (auto &entity : this->_gameEntities) {
        auto components = entity.get()->getComponents();
        for (auto &component : components) {
            if (component.get()->getType() == shared::games::components::TEXTURE) {
                auto texture = std::dynamic_pointer_cast<shared::games::components::ITextureComponent>(component);
                unsigned int index = texture.get()->getZIndex();
                entitiesTextureProps[index].push_back(this->_getTextureEntity(texture));
            }
        }
    }
    this->_window.get()->clear();
    auto textPropsIt = entitiesTextProps.begin();
    auto texturePropsIt = entitiesTextureProps.begin();
    while (texturePropsIt != entitiesTextureProps.end() || textPropsIt != entitiesTextProps.end()) {
        if (texturePropsIt != entitiesTextureProps.end()) {
            for (auto &textureProps : texturePropsIt->second)
                this->_window.get()->render(textureProps);
            texturePropsIt++;
        }
        if (textPropsIt != entitiesTextProps.end()) {
            for (auto &textProps : textPropsIt->second)
                this->_window.get()->render(textProps);
            textPropsIt++;
        }
    }
    this->_window.get()->display();
}

void Core::run()
{
    auto previousTime = std::chrono::high_resolution_clock::now();

    this->_initGame();
    this->_initWindow();
    while (this->_window.get()->isOpen()) {
        auto currentTime = std::chrono::high_resolution_clock::now();
        auto deltaTime = std::chrono::duration_cast<std::chrono::milliseconds>(previousTime - currentTime).count();
        previousTime = currentTime;

        this->_game.get()->compute(deltaTime);
        this->_gameEntities = this->_game.get()->getEntities();
        this->_renderEntities();
    }
}
