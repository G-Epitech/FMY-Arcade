/*
** EPITECH PROJECT, 2024
** arcade-shared
** File description:
** export
*/

#include "SnakeGameProvider.hpp"
#include "shared/types/Libraries.hpp"

using namespace shared::games;
using namespace shared::types;

extern "C" {
LibraryType SHARED_LIBRARY_TYPE_GETTER_NAME(void) {
    return LibraryType::GAME;
}

IGameProvider *SHARED_GAME_PROVIDER_GETTER_NAME(void) {
    return new arcade::games::snake::SnakeGameProvider();
}
}
