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
        return shared::types::LibraryType::GAME;
    }

/*    std::shared_ptr<shared::games::IGameProvider> SHARED_GAME_PROVIDER_LOADER_NAME(void)
    {
        return std::make_shared<GameClass>(...)
    }*/
}
