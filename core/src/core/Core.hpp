/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Core
*/

#pragma once

#include <map>
#include "types/Providers.hpp"
#include "shared/games/components/ITextComponent.hpp"
#include "shared/games/components/ITextureComponent.hpp"
#include "shared/games/components/IDisplayableComponent.hpp"

using namespace shared::graphics;

class Core {
    public:
        Core(GameProviders &gameProviders, GraphicsProviders &graphicsProviders);
        ~Core();

        /**
         * @brief Run the core
         * 
         */
        void run();

    protected:
    private:
        std::shared_ptr<shared::games::IGame> _game;
        std::shared_ptr<IWindow> _window;
        std::unique_ptr<shared::games::IGameProvider> &_gameProvider;
        std::unique_ptr<IGraphicsProvider> &_graphicsProvider;
        std::map<std::string, std::shared_ptr<IFont>> _fonts;
        std::map<std::string, std::shared_ptr<ITexture>> _textures;
        const GameProviders &_gameProviders;
        const GraphicsProviders &_graphicsProviders;
        shared::games::entity::EntitiesMap _gameEntities;

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
         * @brief Get the texture entity
         * 
         * @param texture The texture component
         * @return The texture entity
         */
        TextureProps _getTextureEntity(std::shared_ptr<shared::games::components::ITextureComponent> texture);

        /**
         * @brief Get the text entity
         * 
         * @param text The text component
         * @return The text entity
         */
        TextProps _getTextEntity(std::shared_ptr<shared::games::components::ITextComponent> text);

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
};
