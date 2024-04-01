/*
** EPITECH PROJECT, 2024
** ADisplayableComponent.hpp
** File description:
** ADisplayableComponent class
*/

#pragma once

#include "shared/games/components/IDisplayableComponent.hpp"
#include "PositionableComponent.hpp"

namespace arcade::games::common::components {
    class ADisplayableComponent;
}

class arcade::games::common::components::ADisplayableComponent : public virtual shared::games::components::IDisplayableComponent, public PositionableComponent {
public:
    ~ADisplayableComponent() override = default;

    /**
     * @brief Get size of the entity (tiles)
     *
     */
    Vector2u &getSize() noexcept override;

    /**
     * @brief Get Z index that is usefull for display prioroty
     *
     */
    unsigned int &getZIndex() noexcept override;

    /**
     * @brief On click event handler for the entity
     * @param ctx Context of the game
     */
    void onMousePress(std::shared_ptr<shared::games::IGame> &ctx) override;

    /**
     * @brief On release event handler for the entity
     * @param ctx Context of the game
     */
    void onMouseRelease(std::shared_ptr<shared::games::IGame> &ctx) override;

    /**
     * @brief On hover event handler for the entity
     * @param ctx Context of the game
     */
    void onMouseHover(std::shared_ptr<shared::games::IGame> &ctx) override;

protected:
    /**
     * Create a displayable component
     * @param entity
     * @param size
     * @param zindex
     */
    explicit ADisplayableComponent(shared::games::entity::IEntity &entity, Vector2u size, unsigned int zindex);

    Vector2u _size;
    unsigned int _zindex;
};
