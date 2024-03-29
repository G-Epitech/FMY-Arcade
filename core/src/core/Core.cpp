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

Core::Core(GameProviders &gameProviders, GraphicsProviders &graphicsProviders) :
    _gameProviders(gameProviders), _graphicsProviders(graphicsProviders),
    _gameProvider(gameProviders.at(0)), _graphicsProvider(graphicsProviders.at(0)) {}

Core::~Core() {}

void Core::_initGame()
{
    this->_game = this->_gameProvider.get()->createInstance();
}

void Core::_initWindow()
{
    auto gameManifest = this->_game.get()->getManifest();
    IWindow::WindowInitProps windowInitProps {
        this->_game.get()->getSize(),
        IWindow::WINDOWED,
        this->_game.get()->getFps(),
        gameManifest.name,
        gameManifest.iconPath
    };

    this->_window = this->_graphicsProvider.get()->createWindow(windowInitProps);
}

std::shared_ptr<ITexture> Core::_getTexture(std::string bin, std::string ascii)
{
    if (this->_textures.find(bin + ascii) == this->_textures.end())
        this->_textures[bin + ascii] = this->_graphicsProvider.get()->createTexture(bin, ascii);
    return this->_textures[bin + ascii];
}

std::shared_ptr<IFont> Core::_getFont(std::string path)
{
    if (this->_fonts.find(path) == this->_fonts.end())
        this->_fonts[path] = this->_graphicsProvider.get()->createFont(path);
    return this->_fonts[path];
}

TextureProps Core::_getTextureEntity(std::shared_ptr<shared::games::components::ITextureComponent> texture)
{
    auto textureProps = texture.get()->getTextureProps();
    TextureProps entityTextureProps {
        this->_getTexture(textureProps.sources.bin, textureProps.sources.ascii),
        textureProps.sources.binTileSize,
        textureProps.origin,
        texture.get()->getSize(),
        texture.get()->getPosition()
    };

    return entityTextureProps;
}

TextProps Core::_getTextEntity(std::shared_ptr<shared::games::components::ITextComponent> text)
{
    auto textProps = text->getTextProps();
    TextProps entityTextProps {
        this->_getFont(textProps.font.path),
        textProps.font.size,
        textProps.content,
        static_cast<TextAlign>(textProps.align),
        static_cast<TextVerticalAlign>(textProps.verticalAlign),
        textProps.color,
        text->getSize(),
        text->getPosition()
    };

    return entityTextProps;
}

void Core::_renderTextureProps(std::map<unsigned int, std::vector<TextureProps>> &textures, std::map<unsigned int, std::vector<TextureProps>>::iterator &texturePropsIt)
{
    if (texturePropsIt == textures.end())
        return;
    for (auto &textureProps : texturePropsIt->second)
        this->_window.get()->render(textureProps);
    texturePropsIt++;
}

void Core::_renderTextProps(std::map<unsigned int, std::vector<TextProps>> &texts, std::map<unsigned int, std::vector<TextProps>>::iterator &textPropsIt)
{
    if (textPropsIt == texts.end())
        return;
    for (auto &textureProps : textPropsIt->second)
        this->_window.get()->render(textureProps);
    textPropsIt++;
}

void Core::_renderProps(std::map<unsigned int, std::vector<TextureProps>> &textures, std::map<unsigned int, std::vector<TextProps>> &texts)
{
    auto textPropsIt = texts.begin();
    auto texturePropsIt = textures.begin();

    while (texturePropsIt != textures.end() || textPropsIt != texts.end()) {
        if (textPropsIt != texts.end()) {
            if (texturePropsIt->first <= textPropsIt->first)
                this->_renderTextureProps(textures, texturePropsIt);
        } else {
            this->_renderTextureProps(textures, texturePropsIt);
        }
        if (texturePropsIt != textures.end()) {
            if (textPropsIt->first <= texturePropsIt->first)
                this->_renderTextProps(texts, textPropsIt);
        } else {
            this->_renderTextProps(texts, textPropsIt);
        }
    }
}

void Core::_renderEntities()
{
    std::map<unsigned int, std::vector<TextureProps>> entitiesTextureProps;
    std::map<unsigned int, std::vector<TextProps>> entitiesTextProps;

    for (auto &entity : this->_gameEntities) {
        auto components = entity.get()->getComponents();
        for (auto &component : components) {
            if (component.get()->getType() == shared::games::components::TEXTURE) {
                auto texture = std::dynamic_pointer_cast<shared::games::components::ITextureComponent>(component);
                unsigned int index = texture.get()->getZIndex();
                entitiesTextureProps[index].push_back(this->_getTextureEntity(texture));
            }
            if (component.get()->getType() == shared::games::components::TEXT) {
                auto texture = std::dynamic_pointer_cast<shared::games::components::ITextComponent>(component);
                unsigned int index = texture.get()->getZIndex();
                entitiesTextProps[index].push_back(this->_getTextEntity(texture));
            }
        }
    }
    this->_window.get()->clear();
    this->_renderProps(entitiesTextureProps, entitiesTextProps);
    this->_window.get()->display();
}

void Core::run()
{
    auto previousTime = std::chrono::high_resolution_clock::now();

    this->_initGame();
    this->_initWindow();
    while (this->_window.get()->isOpen()) {
        auto currentTime = std::chrono::high_resolution_clock::now();
        auto deltaTime = std::chrono::duration_cast<std::chrono::milliseconds>(previousTime - currentTime);
        previousTime = currentTime;

        this->_game.get()->compute(deltaTime);
        this->_gameEntities = this->_game.get()->getEntities();
        this->_renderEntities();
    }
}
