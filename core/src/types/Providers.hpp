/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Providers
*/

#pragma once

#include <map>
#include "shared/types/Libraries.hpp"

typedef std::map<std::string, std::shared_ptr<shared::games::IGameProvider>> GameProviders;
typedef std::map<std::string, std::shared_ptr<shared::graphics::IGraphicsProvider>> GraphicsProviders;
