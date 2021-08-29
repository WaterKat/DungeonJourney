//Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

#include "Game.h"

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
        "You think about your dear "+_worldInfo.GoalItem+". If you keep going you'll finally reach it.\n"
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

    //Battle Start

    std::cout << std::string(27, ' ') + "BATTLE!" + std::string(27, ' ') + "\n";
    std::cout << std::string(61, '~') + "\n";
    std::cout << "\n";

    Entity _wolf = Entity::GetWolf();
    
    std::cout << "You have been ambushed!\n";
    std::cout << "You are faced against a " + _wolf.Name + "!\n";
    std::cout << "\n";
    
    while (true)
    {
        std::cout << std::string(27, '~') + "\n";
        AttackSequence(_wolf, _player);
        std::cout << "\n";
        std::cout << std::string(27, '~') + "\n";
        AttackSequence(_player, _wolf);
        std::cout << "\n";
    }

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
