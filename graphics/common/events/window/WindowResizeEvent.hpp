/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** WindowCloseEvent.hpp
*/

#pragma once

#include "shared/graphics/events/IEvent.hpp"

using namespace shared::graphics::events;

namespace arcade::graphics::common::events {
    class WindowResizeEvent;
}


class arcade::graphics::common::events::WindowResizeEvent: public IEvent {
public:
    WindowResizeEvent() = default;
    ~WindowResizeEvent() override = default;

    EventType getType() const noexcept override {
        return WINDOW_RESIZE;
    }
};
