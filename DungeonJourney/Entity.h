#pragma once

#include "Weapon.h"
#include "StatBlockInfo.h"

namespace EntityCore
{
    class Entity
    {
    public:
        std::string Name;
        int Health = 100;
        int MaxHealth = 100;

        int ArmorClass = 10;

        StatBlockInfo StatBlock;

        Weapon EquippedWeapon;

        static Entity GetWolf();
        static Entity GetBasePlayer();
    };
}