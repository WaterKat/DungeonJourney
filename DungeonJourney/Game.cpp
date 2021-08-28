//Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "Game.h"

class WorldInfo;
class Entity;
class Weapon;

class Weapon
{
public:
    std::string Name = "Fist";
    int BaseDamage = 5;
    int NumberOfAttacks = 1;
    int ArmorClassBonus = 0;

    static Weapon GetSwordAndShield()
    {
        Weapon _newWeapon;
        _newWeapon.Name = "Sword and Shield";
        _newWeapon.BaseDamage = 20;
        _newWeapon.ArmorClassBonus = 2;
        return _newWeapon;
    }
    static Weapon GetDaggers()
    {
        Weapon _newWeapon;
        _newWeapon.Name = "Daggers";
        _newWeapon.BaseDamage = 15;
        _newWeapon.NumberOfAttacks = 2;
        return _newWeapon;
    }
    static Weapon GetSpear()
    {
        Weapon _newWeapon;
        _newWeapon.Name = "Spear";
        _newWeapon.BaseDamage = 34;
        return _newWeapon;
    }
};

class Entity
{
public:
    std::string Name;
    int Health = 100;
    int MaxHealth = 100;

    int ArmorClass = 10;

    Weapon EquippedWeapon;

    static Entity GetWolf() 
    {
        Entity _newEntity;
        _newEntity.Name = "Wolf";
        _newEntity.MaxHealth = 11;
        _newEntity.Health = 11;
        _newEntity.ArmorClass = 13;
        return _newEntity;
    }
    static Entity GetBasePlayer()
    {
        Entity _newEntity;
        _newEntity.Name = "Player";
        _newEntity.MaxHealth = 12;
        _newEntity.Health = 12;
        _newEntity.ArmorClass = 14; //ScaleMail
        return _newEntity;
    }
};

class WorldInfo
{
public:
    std::string GoalLocation = "Mordor";
    std::string GoalItem = "Ring";
};

int main()
{
    Entity _player = Entity::GetBasePlayer();
    WorldInfo _worldInfo;

    std::cout << "\n";
    std::cout << "\tWelcome, to your adventurous Dungeon Journey!\t\n";
    std::cout << std::string(61, '~') + "\n";
    std::cout << "\n";


    std::cout << "You, a lone adventurer, sit near a campfire, your name is... "; std::getline(std::cin, _player.Name);
    std::cout << "\n";

    std::cout << "Hello, " + _player.Name + ". Your journey is about to begin.\n";
    std::cout << "\n";

    std::cout << "You are making your way to... "; std::getline(std::cin, _worldInfo.GoalLocation);
    std::cout << "\n";

    std::cout << "Once there you will find your prized... "; std::getline(std::cin, _worldInfo.GoalItem);
    std::cout << "\n";

    std::cout <<
        _player.Name + " you look at the night sky in awe of the beauty of nature.\n"
        "You hear crickets, frog croaks, and the soothing crackling of your midnight fire.\n"
        "But this isn't a peaceful world, and you know it's only a matter of time until you have to fight for you life.\n";
    std::cout << "\n";

    std::system("pause");
    std::cout << "\n";

    std::cout <<
        "You are starting to fall asleep, but you hear the cracking of twigs.\n"
        "Something is coming.\n"
        "You don't have time to prepare!\n";
    std::cout << "\n";

    {
        int _weaponType = 0;

        int _weaponLabelLength = 4;
        std::string _weaponTypeLabels[] =
        {
            "Debug Weapon",
            "Sword and Shield",
            "Daggers",
            "Spear",
        };

        while ((_weaponType < 1) || (_weaponType >= _weaponLabelLength))
        {
            std::cout << "You reach for your... \n";

            for (int i = 1; i < _weaponLabelLength; i++)
            {
                std::cout << std::to_string(i) + ": " + _weaponTypeLabels[i] + "\n";
            }
            std::cout << "\n";

            std::cout << "Number: ";

            if (std::cin >> _weaponType)
            {
                if ((_weaponType > 0) && (_weaponType < _weaponLabelLength))
                    break;
            }
            else
            {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
            }

            std::cout << "\n";
        }
        std::cout << "\n";


        if (_weaponType == 1)
            _player.EquippedWeapon = Weapon::GetSwordAndShield();
        if (_weaponType == 2)
            _player.EquippedWeapon = Weapon::GetDaggers();
        if (_weaponType == 3)
            _player.EquippedWeapon = Weapon::GetSpear();
    }

    std::cout << "You reach for your "+_player.EquippedWeapon.Name+"!\n";
    std::cout << "\n";

    std::cout << std::string(27, ' ') + "BATTLE!" + std::string(27, ' ') + "\n";
    std::cout << std::string(61, '~') + "\n";
    std::cout << "\n";

    Entity _wolf = Entity::GetWolf();
        std::cout << "You have been ambushed!\n";
    std::cout << "You are faced against a " + _wolf.Name + "!\n";
    std::cout << "\n";

    std::string _attackName = "Bite";
    std::cout << _wolf.Name + " tries to " + _attackName + "!\n";
    std::cout << "\n";

    std::system("pause");
    std::cout << "\n";

    int _attackRoll = rand() % 20 + 1;
    int _ac = _player.ArmorClass;
    if (_attackRoll > _ac) 
    {
        if (_attackRoll <= _ac + _player.EquippedWeapon.ArmorClassBonus) 
        {
            std::cout << "You were able to block the attack with your " + _player.EquippedWeapon.Name + "!\n";
        }
        else 
        {
            std::cout << "It hits!\n";
            std::cout << "You take a total of " + std::to_string(_wolf.EquippedWeapon.BaseDamage) + " damage!\n";
            _player.Health -= _wolf.EquippedWeapon.BaseDamage;
        }
    }
    else 
    {
        std::cout << "The wolf misses its attack!\n";
    }
    std::clog << _wolf.Name + " rolled a " + std::to_string(_attackRoll) + "\n";
    std::cout << "\n";

    std::cout << "You have " + std::to_string(_player.Health) + " health.\n";
    std::cout << "What will you do?\n";

    std::cout << "\n\nEND.\n\n";
    return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
