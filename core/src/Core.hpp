/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Core
*/

#pragma once

#include <map>
#include "types/Providers.hpp"
#include "shared/graphics/ISound.hpp"
#include "shared/graphics/events/IKeyEvent.hpp"
#include "shared/graphics/events/IMouseEvent.hpp"
#include "shared/graphics/events/IMouseButtonEvent.hpp"
#include "shared/games/components/ITextComponent.hpp"
#include "shared/games/components/ITextureComponent.hpp"
#include "shared/games/components/IKeyboardComponent.hpp"
#include "shared/games/components/IDisplayableComponent.hpp"
#include "shared/games/components/ICollidableComponent.hpp"
#include "shared/games/components/ISoundComponent.hpp"

using namespace shared::graphics;
using namespace shared::games;

class Core {
    public:
        Core(GameProviders &gameProviders, GraphicsProviders &graphicsProviders);
        ~Core();

        /**
         * @brief Run the core
         * 
         */
        void run();

    private:

        typedef struct {
            std::shared_ptr<ISound> sound;
            ISound::SoundState previousGraphicState;
            components::SoundState previousGameState;
        } SoundProps;

        std::shared_ptr<IGame> _game;
        std::shared_ptr<IWindow> _window;
        std::shared_ptr<IGameProvider> &_gameProvider;
        std::shared_ptr<IGraphicsProvider> &_graphicsProvider;
        std::map<std::string, std::shared_ptr<IFont>> _fonts;
        std::map<std::string, std::shared_ptr<ITexture>> _textures;
        std::map<std::string, SoundProps> _sounds;
        GameProviders &_gameProviders;
        GraphicsProviders &_graphicsProviders;
        entity::EntitiesMap _gameEntities;

        /**
         * @brief Initialize the window
         * 
         */
        void _initWindow();

        /**
         * @brief Initialize the game
         * 
         */
        void _initGame();

        /**
         * @brief Render all entities
         * 
         */
        void _renderEntities();

        /**
         * @brief Get a texture
         * 
         * @param bin Path to the binary file
         * @param ascii Path to the ascii file
         * @return The correct texture
         */
        std::shared_ptr<ITexture> _getTexture(std::string bin, std::string ascii);

        /**
         * @brief Get a font
         * 
         * @param path Path to the font file
         * @return The correct font
         */
        std::shared_ptr<IFont> _getFont(std::string path);

        /**
         * @brief Get a sound
         * 
         * @param path Path to the sound file
         * @return The correct sound
         */
        SoundProps _getSound(std::string path);

        /**
         * @brief Get the texture entity
         * 
         * @param texture The texture component
         * @return The texture entity
         */
        TextureProps _getTextureEntity(std::shared_ptr<components::ITextureComponent> texture);

        /**
         * @brief Get the text entity
         * 
         * @param text The text component
         * @return The text entity
         */
        TextProps _getTextEntity(std::shared_ptr<components::ITextComponent> text);

        /**
         * @brief Render the props
         * 
         * @param textures The textures
         * @param texts The texts
         */
        void _renderProps(std::map<unsigned int, std::vector<TextureProps>> &textures, std::map<unsigned int, std::vector<TextProps>> &texts);

        /**
         * @brief Render the texture props
         * 
         * @param textures The textures
         * @param texturePropsIt The iterator
         */
        void _renderTextureProps(std::map<unsigned int, std::vector<TextureProps>> &textures, std::map<unsigned int, std::vector<TextureProps>>::iterator &texturePropsIt);
    
        /**
         * @brief Render the text props
         * 
         * @param texts The texts
         * @param textPropsIt The iterator
         */
        void _renderTextProps(std::map<unsigned int, std::vector<TextProps>> &texts, std::map<unsigned int, std::vector<TextProps>>::iterator &textPropsIt);

        /**
         * @brief Handle the events
         * 
         */
        void _handleEvents();

        /**
         * @brief Handle the component events
         * 
         * @param events Events to handle
         * @param component The component
         */
        void _handleComponentEvents(std::vector<events::EventPtr> &events, std::shared_ptr<components::IComponent> &component);

        /**
         * @brief Handle the keyboard events
         * 
         * @param events Events to handle
         * @param component The keyboard component
         */
        void _handleKeyboardEvents(std::vector<events::EventPtr> &events, std::shared_ptr<components::IKeyboardComponent> &component);

        /**
         * @brief Handle the displayable events
         * 
         * @param events Events to handle
         * @param component The displayable component
         */
        void _handleDisplayableEvents(std::vector<events::EventPtr> &events, std::shared_ptr<components::IDisplayableComponent> &component);

        /**
         * @brief Handle the collidable events
         * 
         * @param events Events to handle
         * @param component The collidable component
         */
        void _handleCollidableComponents(std::shared_ptr<components::ICollidableComponent> &component);

        /**
         * @brief Handle the collisions
         * 
         * @param component The collidable component
         * @param target The target collidable component
         */
        void _handleCollisions(std::shared_ptr<components::ICollidableComponent> &component, std::shared_ptr<components::ICollidableComponent> &target);

        /**
         * @brief Handle the key press event
         * 
         * @param event The key event
         * @param component The keyboard component
         */
        void _handleKeyPress(std::shared_ptr<events::IKeyEvent> &event, std::shared_ptr<components::IKeyboardComponent> &component);

        /**
         * @brief Handle the key release event
         * 
         * @param event The key event
         * @param component The keyboard component
         */
        void _handleKeyRelease(std::shared_ptr<events::IKeyEvent> &event, std::shared_ptr<components::IKeyboardComponent> &component);

        /**
         * @brief Handle the mouse button press event
         * 
         * @param event The mouse button event
         * @param component The displayable component
         */
        void _handleMouseButtonPress(std::shared_ptr<events::IMouseButtonEvent> &event, std::shared_ptr<components::IDisplayableComponent> &component);

        /**
         * @brief Handle the mouse button release event
         * 
         * @param event The mouse button event
         * @param component The displayable component
         */
        void _handleMouseButtonRelease(std::shared_ptr<events::IMouseButtonEvent> &event, std::shared_ptr<components::IDisplayableComponent> &component);

        /**
         * @brief Handle the mouse move event
         * 
         * @param event The mouse event
         * @param component The displayable component
         */
        void _handleMouseMove(std::shared_ptr<events::IMouseEvent> &event, std::shared_ptr<components::IDisplayableComponent> &component);

        /**
         * @brief Handle the window close event
         * 
         */
        void _handleWindowClose();

        /**
         * @brief Handle the window resize event
         * 
         */
        void _handleWindowResize();

        /**
         * @brief Prevent the window from closing
         * 
         * @param events The events
         */
        void _preventWindowClose(std::vector<events::EventPtr> events);

        /**
         * @brief Handle the key press event
         * 
         * @param event The key event
         */
        void _handleKeyPress(std::shared_ptr<events::IKeyEvent> &event);

        /**
         * @brief Handle the key release event
         * 
         * @param event The key event
         */
        void _handleKeyRelease(std::shared_ptr<events::IKeyEvent> &event);

        /**
         * @brief Convert the key press data
         * 
         * @param type The type of the key
         * @param code The code of the key
         * @return The converted key press data
         */
        components::IKeyboardComponent::KeyData _convertKeyPressData(events::IKeyEvent::KeyType type, events::IKeyEvent::KeyCode code);

        /**
         * @brief Handle the mouse button press event
         * 
         * @param event The mouse button event
         */
        void _handleSoundComponent(std::shared_ptr<components::ISoundComponent> &component);
};
