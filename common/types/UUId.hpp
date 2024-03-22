/*
** EPITECH PROJECT, 2024
** arcade-shared
** File description:
** UUId
*/

#pragma once

#include <string>

#include <uuid/uuid.h>

namespace shared::types {
    class UUId;
}

class shared::types::UUId
{
    public:
        UUId(void);
        ~UUId();

        /**
         * @brief Assign same value to this UUId
         *
         * @param other UUId in whcih value is to be assigned
         * @return Passed instance of UUId
         */
        UUId &operator=(const UUId &other);

        /**
         * @brief Equality operator
         *
         * @param other UUId to be compared
         * @return Equality status
         */
        bool operator==(const UUId &other) const;

        /**
         * @brief Different operator
         *
         * @param other UUId to be compared
         * @return Difference status
         */
        bool operator!=(const UUId &other) const;

        /**
         * @brief Operator to compare if current UUId is less than other UUId
         *
         * @param other Other UUId to be compared
         * @return Status of comparison
         */
        bool operator<(const UUId &other) const;

        /**
         * @brief Operator to compare if current UUId is greter than other UUId
         *
         * @param other Other UUId to be compared
         * @return Status of comparison
         */
        bool operator>(const UUId &other) const;

        /**
         * @brief Operator to compare if current UUId is less than or equal to other UUId
         *
         * @param other Other UUId to be compared
         * @return Status of comparison
         */
        bool operator<=(const UUId &other) const;

        /**
         * @brief Operator to compare if current UUId is greater than or equal to other UUId
         *
         * @param other Other UUId to be compared
         * @return Status of comparison
         */
        bool operator>=(const UUId &other) const;

        /**
         * @brief Convert UUId to string
         *
         * @return String representation of UUId
         */
        std::string toString(void) const;

    private:
        uuid_t _uuid;
};
