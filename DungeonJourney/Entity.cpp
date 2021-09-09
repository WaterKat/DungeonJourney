#include "Entity.h"

using namespace EntityCore;

Entity Entity::GetWolf()
{
    Entity _newEntity;
    _newEntity.Name = "Wolf";
    _newEntity.MaxHealth = 11;
    _newEntity.Health = 11;
    _newEntity.ArmorClass = 13;
    _newEntity.EquippedWeapon = Weapon::GetJaws();
    _newEntity.StatBlock.SetValues(12, 15, 12, 3, 12, 6);
    return _newEntity;
}

Entity Entity::GetBasePlayer()
{
    Entity _newEntity;
    _newEntity.Name = "Player";
    _newEntity.MaxHealth = 12;
    _newEntity.Health = 12;
    _newEntity.ArmorClass = 14; //ScaleMail
    _newEntity.StatBlock.SetValues(10, 10, 10, 10, 10, 10);
    return _newEntity;
}