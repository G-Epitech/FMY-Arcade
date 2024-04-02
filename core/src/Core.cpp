/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Core
*/

#include <iostream>

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
    this->_game = this->_gameProvider->createInstance();
}

void Core::_initWindow()
{
    auto gameManifest = this->_game->getManifest();
    IWindow::WindowInitProps windowInitProps {
        this->_game->getSize(),
        IWindow::WINDOWED,
        this->_game->getFps(),
        gameManifest.name,
        gameManifest.iconPath
    };

    this->_window = this->_graphicsProvider->createWindow(windowInitProps);
}

std::shared_ptr<ITexture> Core::_getTexture(std::string bin, std::string ascii)
{
    if (this->_textures.find(bin + ascii) == this->_textures.end())
        this->_textures[bin + ascii] = this->_graphicsProvider->createTexture(bin, ascii);
    return this->_textures[bin + ascii];
}

std::shared_ptr<IFont> Core::_getFont(std::string path)
{
    if (this->_fonts.find(path) == this->_fonts.end())
        this->_fonts[path] = this->_graphicsProvider->createFont(path);
    return this->_fonts[path];
}

Core::SoundProps Core::_getSound(std::string path)
{
    if (this->_sounds.find(path) == this->_sounds.end()) {
        SoundProps soundProps {
            this->_graphicsProvider->createSound(path),
            ISound::SoundState::STOP,
            components::STOP
        };
        soundProps.sound->setState(ISound::SoundState::STOP);
        this->_sounds[path] = soundProps;
    }
    return this->_sounds[path];
}

TextureProps Core::_getTextureEntity(std::shared_ptr<components::ITextureComponent> texture)
{
    auto textureProps = texture->getTextureProps();
    TextureProps entityTextureProps {
        this->_getTexture(textureProps.sources.bin, textureProps.sources.ascii),
        textureProps.sources.binTileSize,
        textureProps.origin,
        texture->getSize(),
        texture->getPosition()
    };

    return entityTextureProps;
}

TextProps Core::_getTextEntity(std::shared_ptr<components::ITextComponent> text)
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
        this->_window->render(textureProps);
    texturePropsIt++;
}

void Core::_renderTextProps(std::map<unsigned int, std::vector<TextProps>> &texts, std::map<unsigned int, std::vector<TextProps>>::iterator &textPropsIt)
{
    if (textPropsIt == texts.end())
        return;
    for (auto &textureProps : textPropsIt->second)
        this->_window->render(textureProps);
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
        auto components = entity->getComponents();
        for (auto &component : components) {
            if (component->getType() == components::TEXTURE) {
                auto texture = std::dynamic_pointer_cast<components::ITextureComponent>(component);
                unsigned int index = texture->getZIndex();
                entitiesTextureProps[index].push_back(this->_getTextureEntity(texture));
            }
            if (component->getType() == components::TEXT) {
                auto texture = std::dynamic_pointer_cast<components::ITextComponent>(component);
                unsigned int index = texture->getZIndex();
                entitiesTextProps[index].push_back(this->_getTextEntity(texture));
            }
        }
    }
    this->_window->clear();
    this->_renderProps(entitiesTextureProps, entitiesTextProps);
    this->_window->display();
}

components::IKeyboardComponent::KeyData Core::_convertKeyPressData(events::IKeyEvent::KeyType type, events::IKeyEvent::KeyCode code)
{
    components::IKeyboardComponent::KeyData keyCodeData;

    if (type == events::IKeyEvent::CHAR) {
        keyCodeData.code.character = code.character;
        keyCodeData.type = components::IKeyboardComponent::CHAR;
    } else if (type == events::IKeyEvent::CONTROL) {
        keyCodeData.code.control = static_cast<components::IKeyboardComponent::ControlCode>(code.control);
        keyCodeData.type = components::IKeyboardComponent::CONTROL;
    } else if (type == events::IKeyEvent::ARROW) {
        keyCodeData.code.arrow = static_cast<components::IKeyboardComponent::ArrowCode>(code.arrow);
        keyCodeData.type = components::IKeyboardComponent::ARROW;
    } else if (type == events::IKeyEvent::FUNC) {
        keyCodeData.code.func = code.func;
        keyCodeData.type = components::IKeyboardComponent::FUNC;
    }
    return keyCodeData;
}

void Core::_preventWindowClose(std::vector<events::EventPtr> events)
{
    for (auto &event : events) {
        auto type = event->getType();
        if (type == events::WINDOW_CLOSE)
            this->_handleWindowClose();
    }
}

void Core::_handleKeyPress(std::shared_ptr<events::IKeyEvent> &keyEvent, std::shared_ptr<components::IKeyboardComponent> &keyboard)
{
    auto keyCode = keyEvent->getKeyCode();
    auto keyType = keyEvent->getKeyType();
    auto keyCodeData = this->_convertKeyPressData(keyType, keyCode);

    keyboard->onKeyPress(this->_game, keyCodeData);
}

void Core::_handleKeyRelease(std::shared_ptr<events::IKeyEvent> &keyEvent, std::shared_ptr<components::IKeyboardComponent> &keyboard)
{
    auto keyCode = keyEvent->getKeyCode();
    auto keyType = keyEvent->getKeyType();
    auto keyCodeData = this->_convertKeyPressData(keyType, keyCode);

    keyboard->onKeyRelease(this->_game, keyCodeData);
}

void Core::_handleMouseButtonPress(std::shared_ptr<events::IMouseButtonEvent> &event, std::shared_ptr<components::IDisplayableComponent> &component)
{
    auto button = event->getButton();
    auto mousePosition = event->getPosition();
    auto entityPosition = component->getPosition();
    auto entitySize = component->getSize();

    if (mousePosition.x >= entityPosition.x && mousePosition.x <= entityPosition.x + entitySize.x &&
        mousePosition.y >= entityPosition.y && mousePosition.y <= entityPosition.y + entitySize.y)
        component->onMousePress(this->_game);
}

void Core::_handleMouseButtonRelease(std::shared_ptr<events::IMouseButtonEvent> &event, std::shared_ptr<components::IDisplayableComponent> &component)
{
    auto button = event->getButton();
    auto mousePosition = event->getPosition();
    auto entityPosition = component->getPosition();
    auto entitySize = component->getSize();

    if (mousePosition.x >= entityPosition.x && mousePosition.x <= entityPosition.x + entitySize.x &&
        mousePosition.y >= entityPosition.y && mousePosition.y <= entityPosition.y + entitySize.y)
        component->onMouseRelease(this->_game);
}

void Core::_handleMouseMove(std::shared_ptr<events::IMouseEvent> &event, std::shared_ptr<components::IDisplayableComponent> &component)
{
    auto mousePosition = event->getPosition();
    auto entityPosition = component->getPosition();
    auto entitySize = component->getSize();

    if (mousePosition.x >= entityPosition.x && mousePosition.x <= entityPosition.x + entitySize.x &&
        mousePosition.y >= entityPosition.y && mousePosition.y <= entityPosition.y + entitySize.y)
        component->onMouseHover(this->_game);
}

void Core::_handleWindowClose()
{
    this->_window->close();
}

void Core::_handleWindowResize()
{
    std::cout << "Window resized" << std::endl;
}

void Core::_handleKeyBoardEvents(std::vector<events::EventPtr> &events, std::shared_ptr<components::IKeyboardComponent> &component)
{
    for (auto &event : events) {
        auto type = event->getType();
        if (type == events::KEY_PRESS) {
            auto keyEvent = std::dynamic_pointer_cast<events::IKeyEvent>(event);
            this->_handleKeyPress(keyEvent, component);
        }
        if (type == events::KEY_RELEASE) {
            auto keyEvent = std::dynamic_pointer_cast<events::IKeyEvent>(event);
            this->_handleKeyRelease(keyEvent, component);
        }
    }
}

void Core::_handleDisplayableEvents(std::vector<events::EventPtr> &events, std::shared_ptr<components::IDisplayableComponent> &component)
{
    for (auto &event : events) {
        auto type = event->getType();
        if (type == events::MOUSE_BTN_PRESS) {
            auto mouseButtonEvent = std::dynamic_pointer_cast<events::IMouseButtonEvent>(event);
            this->_handleMouseButtonPress(mouseButtonEvent, component);
        }
        if (type == events::MOUSE_BTN_RELEASE) {
            auto mouseButtonEvent = std::dynamic_pointer_cast<events::IMouseButtonEvent>(event);
            this->_handleMouseButtonRelease(mouseButtonEvent, component);
        }
        if (type == events::MOUSE_MOVE) {
            auto mouseEvent = std::dynamic_pointer_cast<events::IMouseEvent>(event);
            this->_handleMouseMove(mouseEvent, component);
        }
    }
}

void Core::_handleCollisions(std::shared_ptr<components::ICollidableComponent> &component, std::shared_ptr<components::ICollidableComponent> &target)
{
    auto componentPosition = component->getPosition();
    auto componentSize = component->getSize();
    auto targetPosition = target->getPosition();
    auto targetSize = target->getSize();

    if (componentPosition.x < targetPosition.x + targetSize.x &&
        componentPosition.x + componentSize.x > targetPosition.x &&
        componentPosition.y < targetPosition.y + targetSize.y &&
        componentPosition.y + componentSize.y > targetPosition.y)
        component->onCollide(this->_game, target);
}

void Core::_handleCollidableComponents(std::shared_ptr<components::ICollidableComponent> &component)
{
    for (auto &entity : this->_gameEntities) {
        auto components = entity->getComponents();
        for (auto &entityComponent : components) {
            if (entityComponent->getType() == components::COLLIDABLE) {
                auto collidable = std::dynamic_pointer_cast<components::ICollidableComponent>(entityComponent);
                this->_handleCollisions(component, collidable);
            }
        }
    }
}

void Core::_handleSoundComponent(std::shared_ptr<components::ISoundComponent> &gameSound)
{
    auto gameSoundPath = gameSound->getPath();
    auto sound = this->_getSound(gameSoundPath);

    auto gameSoundState = gameSound->getState();
    auto gameSoundVolume = gameSound->getVolume();
    auto gameSoundLoop = gameSound->getLoop();
    auto graphicSoundState = sound.sound->getState();
    auto graphicSoundVolume = sound.sound->getVolume();
    auto graphicSoundLoop = sound.sound->getLoopState();

    if (gameSoundState != sound.previousGameState) {
        if (gameSoundState == components::PLAY)
            sound.sound->setState(ISound::SoundState::PLAY);
        if (gameSoundState == components::PAUSE)
            sound.sound->setState(ISound::SoundState::PAUSE);
        if (gameSoundState == components::STOP)
            sound.sound->setState(ISound::SoundState::STOP);
        sound.previousGameState = gameSoundState;
    }
    if (graphicSoundState != sound.previousGraphicState) {
        if (graphicSoundState == ISound::SoundState::PLAY)
            gameSound->onStateChange(this->_game, components::PLAY);
        if (graphicSoundState == ISound::SoundState::PAUSE)
            gameSound->onStateChange(this->_game, components::PAUSE);
        if (graphicSoundState == ISound::SoundState::STOP)
            gameSound->onStateChange(this->_game, components::STOP);
    }
    if (gameSoundVolume != graphicSoundVolume)
        sound.sound->setVolume(gameSoundVolume);
    if (gameSoundLoop != graphicSoundLoop)
        sound.sound->setLoopState(gameSoundLoop);
}

void Core::_handleComponentEvents(std::vector<events::EventPtr> &events, std::shared_ptr<components::IComponent> &component)
{
    auto type = component->getType();

    if (type == components::KEYBOARD) {
        auto keyboard = std::dynamic_pointer_cast<components::IKeyboardComponent>(component);
        this->_handleKeyBoardEvents(events, keyboard);
    }
    if (type == components::DISPLAYABLE) {
        auto displayable = std::dynamic_pointer_cast<components::IDisplayableComponent>(component);
        this->_handleDisplayableEvents(events, displayable);
    }
    if (type == components::COLLIDABLE) {
        auto collidable = std::dynamic_pointer_cast<components::ICollidableComponent>(component);
        this->_handleCollidableComponents(collidable);
    }
    if (type == components::SOUND) {
        auto sound = std::dynamic_pointer_cast<components::ISoundComponent>(component);
        this->_handleSoundComponent(sound);
    }
}

void Core::_handleEvents()
{
    auto gameEvents = this->_window->getEvents();

    this->_preventWindowClose(gameEvents);
    for (auto &entity : this->_gameEntities) {
        auto components = entity->getComponents();
        for (auto &component : components) {
            this->_handleComponentEvents(gameEvents, component);
        }
    }
}

void Core::run()
{
    auto previousTime = std::chrono::high_resolution_clock::now();

    this->_initGame();
    this->_initWindow();
    while (this->_window->isOpen()) {
        auto currentTime = std::chrono::high_resolution_clock::now();
        auto deltaTime = std::chrono::duration_cast<std::chrono::milliseconds>(previousTime - currentTime);
        previousTime = currentTime;

        this->_game->compute(deltaTime);
        this->_gameEntities = this->_game->getEntities();
        this->_handleEvents();
        this->_renderEntities();
    }
}
