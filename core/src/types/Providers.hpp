/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Providers
*/

#pragma once

#include "shared/types/Libraries.hpp"

typedef std::vector<std::unique_ptr<shared::games::IGameProvider>> GameProviders;
typedef std::vector<std::unique_ptr<shared::graphics::IGraphicsProvider>> GraphicsProviders;
