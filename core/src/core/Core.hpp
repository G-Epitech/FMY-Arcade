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

class Core {
    public:
        Core(GameProviders gameProviders, GraphicsProviders graphicsProviders);
        ~Core();

        /**
         * @brief Run the core
         * 
         */
        void run();

    protected:
    private:
        std::shared_ptr<shared::games::IGame> _game;
        std::shared_ptr<shared::graphics::IWindow> _window;
        std::shared_ptr<shared::games::IGameProvider> _gameProvider;
        std::shared_ptr<shared::graphics::IGraphicsProvider> _graphicsProvider;
        std::map<std::string, std::shared_ptr<shared::graphics::IFont>> _fonts;
        std::map<std::string, std::shared_ptr<shared::graphics::ITexture>> _textures;
        GameProviders _gameProviders;
        GraphicsProviders _graphicsProviders;
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
        std::shared_ptr<shared::graphics::ITexture> _getTexture(std::string bin, std::string ascii);

        /**
         * @brief Get a font
         * 
         * @param path Path to the font file
         * @return The correct font
         */
        std::shared_ptr<shared::graphics::IFont> _getFont(std::string path);

        /**
         * @brief Get the texture entity
         * 
         * @param texture The texture component
         * @return The texture entity
         */
        shared::graphics::TextureProps _getTextureEntity(std::shared_ptr<shared::games::components::ITextureComponent> texture);

        /**
         * @brief Get the text entity
         * 
         * @param text The text component
         * @return The text entity
         */
        shared::graphics::TextProps _getTextEntity(std::shared_ptr<shared::games::components::ITextComponent> text);
};
