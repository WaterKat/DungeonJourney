//Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

#include "Scenes.h"
#include "Entity.h"
#include "WorldInfo.h"
#include "GameMechanics.h"
#include "Weapon.h"
#include "SaveManager.h"

#include "main.h"

int main()
{
    SaveManager _saveManager;
    WorldInfo _worldInfo;

    Introduction();



    _worldInfo.Player = EntityCore::Entity::GetBasePlayer();
    int _saveSlot = 1;



    int _menuOptionsChoice = Menu(_worldInfo.Player, _worldInfo);

    /*
        "Debug",
        "Start a new journey!",
        "Continue your adventure!",
        "Options",
        "Credits",
        "Quit",
    */
    
    switch (_menuOptionsChoice)
    {
    case 1:
        std::cout << ">> Start a new journey!\n";
        break;
    case 2:
        std::cout << ">> Continue your adventure!\n";


        std::clog << "AT THE MOMENT MENU IS NON FUNCTIONAL\n\n";

        break;
    case 3:
        std::cout << ">> Options\n";
        std::clog << "AT THE MOMENT MENU IS NON FUNCTIONAL\n\n";

        break;
    case 4:
        std::cout << ">> Credits\n";
        std::clog << "AT THE MOMENT MENU IS NON FUNCTIONAL\n\n";

        break;
    case 5:
        std::cout << ">> Quit\n";
        std::system("pause");
        return 0;               //EXIT
        break;
    default:
        break;
    }

    //NEW GAME
    GatherInfo(_worldInfo.Player, _worldInfo);
    
    _saveManager.SaveToSlot(_worldInfo, _saveSlot);

    std::cout << "Hello, " + _worldInfo.Player.Name + ". Your journey is about to begin.\n";
    std::cout << "\n";

    std::cout <<
        _worldInfo.Player.Name + " you look at the night sky in awe of the beauty of nature.\n"
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
        int _weaponLabelsLength = 4;
        std::string _weaponLabels[] =
        {
            "Debug Weapon",
            "Sword and Shield",
            "Daggers",
            "Spear",
        };

        int _weaponType;
        _weaponType = PromptChoice("You reach for your...", _weaponLabels,_weaponLabelsLength);

        if (_weaponType == 1)
            _worldInfo.Player.EquippedWeapon = Weapon::GetSwordAndShield();
        if (_weaponType == 2)
            _worldInfo.Player.EquippedWeapon = Weapon::GetDaggers();
        if (_weaponType == 3)
            _worldInfo.Player.EquippedWeapon = Weapon::GetSpear();
    }

    std::cout << "You reach for your "+ _worldInfo.Player.EquippedWeapon.Name+"!\n";
    std::cout << "\n";

    //Battle Start

    std::cout << std::string(27, ' ') + "BATTLE!" + std::string(27, ' ') + "\n";
    std::cout << std::string(61, '~') + "\n";
    std::cout << "\n";

    EntityCore::Entity _wolf = EntityCore::Entity::GetWolf();
        
    BattleSequence(_wolf, _worldInfo.Player, true);

    std::cout << "What will you do?\n";

    std::cout << "\n\nEND.\n\n";
    return 0;
}

int Menu(EntityCore::Entity& _player, WorldInfo& _worldInfo)
{
    std::string _menuOptions[6] =
    {
        "Debug",
        "Start a new journey!",
        "Continue your adventure!",
        "Options",
        "Credits",
        "Quit",
    };

    int _menuOptionsLength = 6;

    int _menuOptionsChoice;
    _menuOptionsChoice = PromptChoice("Start a new journey? Or continue your adventure?", _menuOptions, _menuOptionsLength);

    return _menuOptionsChoice;
}

void Introduction()
{
    std::cout << "\n";
    std::cout << "\tWelcome, to your adventurous Dungeon Journey!\t\n";
    std::cout << std::string(61, '~') + "\n";
    std::cout << "\n";
    std::cout <<
        "            /\\    /\\        /\\  /\\  /\\      /\\   \n"
        "           /\\/\\  /\\/\\  /\\  /\\/\\/\\/\\/\\/\\    /\\/\\  \n"
        "          /\\/\\ \\/    \\/\\/\\/    \\  /    \\/\\/    \\ \n"
        "         /    \\/      \\   \\     \\/     /  \\     \\ \n"
        ;
    /*
            /\    /\        /\  /\  /\      /\
           /\/\  /\/\  /\  /\/\/\/\/\/\    /\/\
          /\/\ \/    \/\/\/    \  /    \/\/    \
         /    \/      \   \     \/     /  \     \
    */
    std::cout << "\n";
}
void GatherInfo(EntityCore::Entity& _player, WorldInfo& _worldInfo)
{
    std::cout << "You, a lone adventurer, sit near a campfire, your name is... "; std::getline(std::cin, _player.Name);
    std::cout << "\n";

    std::cout << "You are making your way to... "; std::getline(std::cin, _worldInfo.GoalLocation);
    std::cout << "\n";

    std::cout << "Once there you will find your prized... "; std::getline(std::cin, _worldInfo.GoalItem);
    std::cout << "\n";
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