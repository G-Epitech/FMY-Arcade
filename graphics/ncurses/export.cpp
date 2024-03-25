/*
** EPITECH PROJECT, 2024
** arcade-shared
** File description:
** export
*/

#include "shared/games/IGameProvider.hpp"
#include "shared/types/Libraries.hpp"

extern "C" {
    shared::types::LibraryType SHARED_LIBRARY_TYPE_GETTER_NAME(void)
    {
        return shared::types::LibraryType::GRAPHIC;
    }

/*    std::shared_ptr<shared::graphics::IGraphicsProvider> SHARED_GRAPHICS_PROVIDER_LOADER_NAME(void)
    {
        return std::make_shared<RendererClass>(...);
    }*/
}

