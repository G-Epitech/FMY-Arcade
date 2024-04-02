/*
** EPITECH PROJECT, 2024
** arcade-shared
** File description:
** export
*/

#include "shared/games/IGameProvider.hpp"
#include "shared/types/Libraries.hpp"
#include "src/GraphicsProvider.hpp"

using namespace arcade::graphics;
using namespace shared::graphics;
using namespace shared::types;

extern "C" {
    LibraryType SHARED_LIBRARY_TYPE_GETTER_NAME(void)
    {
        return LibraryType::GRAPHIC;
    }

    IGraphicsProvider *SHARED_GRAPHICS_PROVIDER_GETTER_NAME(void)
    {
        return new sfml::GraphicsProvider();
    }
}
