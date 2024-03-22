/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Providers
*/

#pragma once

#include "common/types/Libraries.hpp"

typedef std::vector<std::shared_ptr<shared::games::IGameProvider>> GameProviders;
typedef std::vector<std::shared_ptr<shared::graphics::IGraphicsProvider>> GraphicsProviders;
