/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** AGame.hpp
*/

#pragma once

#include <map>
#include "shared/games/IGame.hpp"
#include "shared/types/Vector.hpp"

namespace arcade::games::common {
    class AGame;
    typedef std::shared_ptr<shared::games::entity::IEntity> EntityPtr;
}

class arcade::games::common::AGame : public shared::games::IGame {
public:
    ~AGame() override = default;

    /**
     * @brief Get map of entities
     *
     * @return Map of entities
     */
    const shared::games::entity::EntitiesMap &getEntities() const override;

    /**
     * @brief Get game size (in tiles)
     *
     * @return Size of the game
     */
    const shared::types::Vector2u getSize() const noexcept override;

    /**
     * @brief Get entity by id
     *
     * @param id Id of the entity
     * @return The specific entity
     */
    EntityPtr getEntityById(const shared::types::UUId &id) const override;

protected:
    /**
     * @brief Construct a new AGame object
     *
     * @param size Size of the game
     */
    explicit AGame(shared::types::Vector2u size);

    /**
     * @brief List of game entities
     */
    shared::games::entity::EntitiesMap _entities;

    /**
     * @brief Game size
     */
    shared::types::Vector2u _size;

    /**
     * @brief Add an entity to the game
     *
     * @param entity Entity to add
     * @return Id of the entity
     * @warning This method is moving ownership of the entity
     */
    shared::types::UUId _registerEntity(EntityPtr entity);
};