#include "Weapon.h"

Weapon Weapon::GetSwordAndShield()
{
    Weapon _newWeapon;
    _newWeapon.Name = "Sword and Shield";
    _newWeapon.AttackName = "Slash";
    _newWeapon.BaseDamage = 20;
    _newWeapon.ArmorClassBonus = 2;
    return _newWeapon;
}
Weapon Weapon::GetDaggers()
{
    Weapon _newWeapon;
    _newWeapon.Name = "Daggers";
    _newWeapon.AttackName = "Stab";
    _newWeapon.AttackSkill = 1; //Dexterity
    _newWeapon.BaseDamage = 15;
    _newWeapon.NumberOfAttacks = 2;
    return _newWeapon;
}
Weapon Weapon::GetSpear()
{
    Weapon _newWeapon;
    _newWeapon.Name = "Spear";
    _newWeapon.AttackName = "Stab";
    _newWeapon.AttackSkill = 1; //Dexterity
    _newWeapon.BaseDamage = 34;
    return _newWeapon;
}
Weapon Weapon::GetJaws()
{
    Weapon _newWeapon;
    _newWeapon.Name = "Jaws";
    _newWeapon.AttackName = "Bite";
    _newWeapon.AttackRollBonus = 4;
    _newWeapon.BaseDamage = 5;
    return _newWeapon;
}
