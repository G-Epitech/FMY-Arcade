/*
** EPITECH PROJECT, 2024
** arcade-shared
** File description:
** LibraryType
*/

#pragma once

#include "../games/IGameProvider.hpp"
#include "../graphics/IGraphicsProvider.hpp"

#define SHARED_GAME_PROVIDER_GETTER_NAME arcadeLibGetGameProvider
#define SHARED_GRAPHICS_PROVIDER_GETTER_NAME arcadeLibGetGraphicsProvider
#define SHARED_LIBRARY_TYPE_GETTER_NAME arcadeLibGetType
#define STRINGIFY(x) #x
#define SHARED_STRINGIFY(x) STRINGIFY(x)

namespace shared::types
{
  typedef enum {
    GAME,
    GRAPHIC,
  } LibraryType;

  typedef games::IGameProvider* (*GameProviderGetter)(void);
  typedef graphics::IGraphicsProvider* (*GraphicsProviderGetter)(void);
  typedef LibraryType (*LibraryTypeGetter)(void);
}
