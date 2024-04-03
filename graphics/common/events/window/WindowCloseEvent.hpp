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
    class WindowCloseEvent;
}


class arcade::graphics::common::events::WindowCloseEvent: public IEvent {
public:
    WindowCloseEvent() = default;
    ~WindowCloseEvent() override = default;

    EventType getType() const noexcept override {
        return WINDOW_CLOSE;
    }
};
