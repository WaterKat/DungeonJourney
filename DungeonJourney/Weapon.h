#pragma once

#include <string>

class Weapon
{
public:
    std::string Name = "Fist";
    std::string AttackName = "Punch";
    int BaseDamage = 5;
    int AttackSkill = 0;    //0:Str,1:Dex,2:Con,3:Int,4:Wis,5:Cha
    int NumberOfAttacks = 1;
    int AttackRollBonus = 0;
    int ArmorClassBonus = 0;

    static Weapon GetSwordAndShield();
    static Weapon GetDaggers();
    static Weapon GetSpear();
    static Weapon GetJaws();
};
