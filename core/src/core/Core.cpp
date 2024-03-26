/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Core
*/

#include <memory.h>
#include "Core.hpp"
#include "shared/games/components/IComponent.hpp"
#include "shared/games/components/IDisplayableComponent.hpp"

Core::Core(GameProviders gameProviders, GraphicsProviders graphicsProviders) {
    this->_gameProviders = gameProviders;
    this->_graphicsProviders = graphicsProviders;
}

Core::~Core() {}

void Core::_setup()
{
    shared::graphics::WindowInitProps windowInitProps {
        {0, 0},
        shared::graphics::WINDOWED,
        60,
        "Arcade",
        "icon"
    };

    this->_gameProvider = this->_gameProviders.at(0);
    this->_graphicsProvider = this->_graphicsProviders.at(0);

    this->_game = this->_gameProvider.get()->createInstance();
    windowInitProps.size = this->_game.get()->getSize();
    this->_window = this->_graphicsProvider.get()->createWindow(windowInitProps);
}

void Core::_renderEntities()
{
    shared::games::entity::EntitiesMap entities = this->_game.get()->getEntities();

    for (auto &entity : entities) {
        auto components = entity.second.get()->getComponents();
        for (auto &component : components) {
            if (component.second.get()->getType() == shared::games::components::DISPLAYABLE) {
                auto displayable = std::dynamic_pointer_cast<shared::games::components::IDisplayableComponent>(component.second);
                auto textureProps = displayable.get()->getTextureProps();
                shared::graphics::EntityTextureProps entityTextureProps {
                    this->_graphicsProvider.get()->createTexture(textureProps.sources.bin, textureProps.sources.ascii),
                    textureProps.sources.binTileSize,
                    textureProps.origin
                };
                shared::graphics::EntityProps entityProps {
                    entityTextureProps,
                    displayable.get()->getSize(),
                    displayable.get()->getPosition()
                };
                this->_window.get()->render(entityProps);
            }
        }
    }
}

void Core::run()
{
    this->_setup();
    while (this->_window.get()->isOpen()) {
        this->_window.get()->display();
        this->_window.get()->clear();
    }
}
