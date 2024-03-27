/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Core
*/

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

shared::graphics::EntityProps Core::_getDisplayableEntity(std::shared_ptr<shared::games::components::IDisplayableComponent> displayable)
{
    auto textureProps = displayable.get()->getTextureProps();
    shared::graphics::EntityTextureProps entityTextureProps {
        this->_getTexture(textureProps.sources.bin, textureProps.sources.ascii),
        textureProps.sources.binTileSize,
        textureProps.origin
    };
    shared::graphics::EntityProps entityProps {
        entityTextureProps,
        displayable.get()->getSize(),
        displayable.get()->getPosition()
    };

    return entityProps;
}

void Core::_renderEntities()
{
    shared::games::entity::EntitiesMap entities = this->_game.get()->getEntities();
    std::map<unsigned int, shared::graphics::EntityProps> entitiesProps;

    for (auto &entity : entities) {
        auto components = entity.get()->getComponents();
        for (auto &component : components) {
            if (component.get()->getType() == shared::games::components::DISPLAYABLE) {
                auto displayable = std::dynamic_pointer_cast<shared::games::components::IDisplayableComponent>(component);
                unsigned int index = displayable.get()->getZIndex();
                entitiesProps.insert(std::make_pair(index, this->_getDisplayableEntity(displayable)));
            }
        }
    }
    this->_window.get()->clear();
    for (auto &entity : entitiesProps)
        this->_window.get()->render(entity.second);
    this->_window.get()->display();
}

void Core::run()
{
    this->_initGame();
    this->_initWindow();
    while (this->_window.get()->isOpen()) {
        this->_renderEntities();
    }
}
