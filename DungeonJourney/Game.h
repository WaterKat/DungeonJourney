#pragma once


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

    static Weapon GetSwordAndShield()
    {
        Weapon _newWeapon;
        _newWeapon.Name = "Sword and Shield";
        _newWeapon.AttackName = "Slash";
        _newWeapon.BaseDamage = 20;
        _newWeapon.ArmorClassBonus = 2;
        return _newWeapon;
    }
    static Weapon GetDaggers()
    {
        Weapon _newWeapon;
        _newWeapon.Name = "Daggers";
        _newWeapon.AttackName = "Stab";
        _newWeapon.AttackSkill = 1; //Dexterity
        _newWeapon.BaseDamage = 15;
        _newWeapon.NumberOfAttacks = 2;
        return _newWeapon;
    }
    static Weapon GetSpear()
    {
        Weapon _newWeapon;
        _newWeapon.Name = "Spear";
        _newWeapon.AttackName = "Stab";
        _newWeapon.AttackSkill = 1; //Dexterity
        _newWeapon.BaseDamage = 34;
        return _newWeapon;
    }
    static Weapon GetJaws()
    {
        Weapon _newWeapon;
        _newWeapon.Name = "Jaws";
        _newWeapon.AttackName = "Bite";
        _newWeapon.AttackRollBonus = 4;
        _newWeapon.BaseDamage = 5;
        return _newWeapon;
    }
};

class Entity
{
public:
    class StatBlockInfo
    {
    public:
        class StatInfo
        {
        public:
            int Value = 10;
            int GetModifier() 
            {
                return ((Value - 10) / 2);
            }
        };
        StatInfo Str;
        StatInfo Dex;
        StatInfo Con;
        StatInfo Int;
        StatInfo Wis;
        StatInfo Cha;

        StatInfo operator[](int _index) 
        {
            switch (_index)
            {
            case 0:
                return Str;
                break;
            case 1:
                return Dex;
                break;
            case 2:
                return Con;
                break;
            case 3:
                return Int;
                break;
            case 4:
                return Wis;
                break;
            case 5:
                return Cha;
                break;
            default:
                return Str;
                break;
            }
        }

        void SetValues(int _str, int _dex, int _con, int _int, int _wis, int _cha)
        {
            Str.Value = _str;
            Dex.Value = _dex;
            Con.Value = _con;
            Int.Value = _int;
            Wis.Value = _wis;
            Cha.Value = _cha;
        }
    };

    std::string Name;
    int Health = 100;
    int MaxHealth = 100;

    int ArmorClass = 10;
    
    StatBlockInfo StatBlock;

    Weapon EquippedWeapon;

    static Entity GetWolf()
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
    static Entity GetBasePlayer()
    {
        Entity _newEntity;
        _newEntity.Name = "Player";
        _newEntity.MaxHealth = 12;
        _newEntity.Health = 12;
        _newEntity.ArmorClass = 14; //ScaleMail
        _newEntity.StatBlock.SetValues(10, 10, 10, 10, 10, 10);
        return _newEntity;
    }
};

class WorldInfo
{
public:
    std::string GoalLocation = "Mordor";
    std::string GoalItem = "Ring";
};

int RollD20() 
{
    return rand() % 20 + 1;
}

void AttackSequence(Entity _attacker, Entity _defender) 
{
    std::cout << 
        _attacker.Name + " tries to " + _attacker.EquippedWeapon.AttackName + 
        " with its " + _attacker.EquippedWeapon.Name + "!\n";
    std::cout << "\n";

    std:system("pause");
    std::cout << "\n";

    int _baseRoll = RollD20();
    int _attackRoll = _baseRoll + _attacker.StatBlock[_attacker.EquippedWeapon.AttackSkill].GetModifier() + _attacker.EquippedWeapon.AttackRollBonus;

    std::clog <<
        _attacker.Name + " rolled a " + std::to_string(_attackRoll) + 
        " (Natural Roll: " + std::to_string(_baseRoll) + " + Attack Mod: " + std::to_string(_attacker.StatBlock[_attacker.EquippedWeapon.AttackSkill].GetModifier())
        + " + Weapon Mod: " + std::to_string(_attacker.EquippedWeapon.AttackRollBonus) +
        ") against the defenders Armor Class: " + std::to_string(_defender.ArmorClass + _defender.EquippedWeapon.ArmorClassBonus) +
        "\n";
    std::cout << "\n";

    if (_attackRoll <= _defender.ArmorClass)
    {
        std::cout << _defender.Name + " was able to dodge the attack!\n";
    }
    else if (_attackRoll <= _defender.ArmorClass+_defender.EquippedWeapon.ArmorClassBonus)
    {
        std::cout << 
            _defender.Name + " was able to block the "+_attacker.EquippedWeapon.AttackName+" with their " +
            _defender.EquippedWeapon.Name + "!\n";
    }
    else
    {
        std::cout << "It hits!\n";
        std::cout << "You take a total of " + std::to_string(_attacker.EquippedWeapon.BaseDamage) + " damage!\n";
        _defender.Health -= _attacker.EquippedWeapon.BaseDamage;
    }
    std::cout << "\n";

    std::cout << _defender.Name + " has a total of " + std::to_string(_defender.Health) + " health remaining!\n";

    std::cout << "\n";
}