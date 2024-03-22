/*
** EPITECH PROJECT, 2024
** arcade-shared
** File description:
** UUId
*/

#include "UUId.hpp"


shared::types::UUId::UUId()
{
    uuid_generate(_uuid);
}

shared::types::UUId::~UUId()
{
}

shared::types::UUId &shared::types::UUId::operator=(const UUId &other)
{
    if (this != &other)
        uuid_copy(_uuid, other._uuid);
    return *this;
}

bool shared::types::UUId::operator==(const UUId &other) const
{
    return uuid_compare(_uuid, other._uuid) == 0;
}

bool shared::types::UUId::operator!=(const UUId &other) const
{
    return uuid_compare(_uuid, other._uuid) != 0;
}

bool shared::types::UUId::operator<(const UUId &other) const
{
    return uuid_compare(_uuid, other._uuid) < 0;
}

bool shared::types::UUId::operator>(const UUId &other) const
{
    return uuid_compare(_uuid, other._uuid) > 0;
}

bool shared::types::UUId::operator<=(const UUId &other) const
{
    return uuid_compare(_uuid, other._uuid) <= 0;
}

bool shared::types::UUId::operator>=(const UUId &other) const
{
    return uuid_compare(_uuid, other._uuid) >= 0;
}

std::string shared::types::UUId::toString() const
{
    char str[37];

    uuid_unparse(_uuid, str);
    return std::string(str);
}
