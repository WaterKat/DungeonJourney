#pragma once

#include "Entity.h"

class WorldInfo
{
public:
    int FlagPosition = 0;
    std::string GoalLocation = "Mordor";
    std::string GoalItem = "Ring";
    EntityCore::Entity Player;
};