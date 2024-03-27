/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** AKeyEvent.hpp
*/

#pragma once

#include "shared/graphics/events/IKeyEvent.hpp"

using namespace shared::graphics::events;

namespace arcade::graphics::common::events {
    template<EventType T>
    concept KeyEventType = T == EventType::KEY_PRESS || T == EventType::KEY_RELEASE;

    template<EventType T> requires KeyEventType<T>
    class AKeyEvent;
}

using namespace arcade::graphics::common::events;

template<EventType T> requires KeyEventType<T>
class arcade::graphics::common::events::AKeyEvent: public IKeyEvent {
public:
    ~AKeyEvent() override = default;

    EventType getType() const noexcept override {
        return _type;
    }

protected:
    AKeyEvent(const KeyType keyType, const KeyCode code) : _keyType(keyType), _code(code) {};

    const EventType _type = T;
    const KeyType   _keyType;
    const KeyCode   _code;
};
