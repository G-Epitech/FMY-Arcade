/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Core
*/

#pragma once

#include "types/Providers.hpp"
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
        std::map<std::string, std::shared_ptr<shared::graphics::ITexture>> _textures;
        GameProviders _gameProviders;
        GraphicsProviders _graphicsProviders;

        /**
         * @brief Initialize the core
         * 
         */
        void _initWindow();

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

        void _renderDisplayableEntity(std::shared_ptr<shared::games::components::IDisplayableComponent> displayable);
};
