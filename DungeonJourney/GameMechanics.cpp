#include "GameMechanics.h"

void DisplayEntityInfo(EntityCore::Entity _entity)
{
    std::cout << _entity.Name + "\n";
    std::cout << "Health: " + std::to_string(_entity.Health) + "\n";
    std::cout << "\n";
}

int PromptChoice(std::string _preMessage, std::string _textOptions[], int _textOptionsLength)
{
    int _selectionInt = 0;

    while ((_selectionInt < 1) || (_selectionInt >= _textOptionsLength))
    {
        //Message before choices that should be repeated after every attempt
        std::cout << _preMessage;
        std::cout << "\n";
        std::cout << "\n";

        //The actual choice logic
        for (int i = 1; i < _textOptionsLength; i++)
        {
            std::cout << std::to_string(i) + ": " + _textOptions[i] + "\n";
        }
        std::cout << "\n";

        std::cout << "Number: ";

        if (std::cin >> _selectionInt)
        {
            if ((_selectionInt > 0) && (_selectionInt < _textOptionsLength))
            {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                break;
            }
        }
        else
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }

        std::cout << "\n";
    }
    std::cout << "\n";

    return _selectionInt;
}

void PlayerTurnSequence(EntityCore::Entity& _player, EntityCore::Entity& _enemy)
{
    std::string _battleOptions[] =
    {
        "Debug",
        "Attack",   //1
        "Use Item", //2
        "Defend",   //3
        "Run",      //4
    };
    int _battleOptionsLength = 5;

    bool _actionTaken = false;

    int _battleOptionChoice;

    while (!_actionTaken)
    {
        _battleOptionChoice = PromptChoice("You're in battle! What will you do?", _battleOptions, _battleOptionsLength);

        switch (_battleOptionChoice)
        {
        case 1:
            AttackSequence(_player, _enemy);
            _actionTaken = true;
            break;
        case 2:
            std::cout << "You have no items to use!\n";
            std::cout << "\n";
            std::system("pause");
            break;
        case 3:
            std::cout << "You brace yourself!\n";
            std::cout << "\n";
            std::system("pause");
            break;
        case 4:
            std::cout << "You can't run from this encounter!\n";
            std::cout << "\n";
            std::system("pause");
            break;
        default:
            break;
        }
    }
    std::cout << "\n";
}

void AttackSequence(EntityCore::Entity& _attacker, EntityCore::Entity& _defender)
{
    std::cout << _attacker.Name + "'s Round\n";
    std::cout << std::string(27, '~') + "\n";
    std::cout << "\n";

    std::cout <<
        _attacker.Name + " tries to " + _attacker.EquippedWeapon.AttackName +
        " with its " + _attacker.EquippedWeapon.Name + "!\n";
    std::cout << "\n";

    int _baseRoll = Dice::RollD20();
    int _attackRoll = _baseRoll + _attacker.StatBlock[_attacker.EquippedWeapon.AttackSkill].GetModifier() + _attacker.EquippedWeapon.AttackRollBonus;

    std::clog <<
        _attacker.Name + " rolled a " + std::to_string(_attackRoll) +
        " (Natural Roll: " + std::to_string(_baseRoll) + " + Attack Mod: " + std::to_string(_attacker.StatBlock[_attacker.EquippedWeapon.AttackSkill].GetModifier())
        + " + Weapon Mod: " + std::to_string(_attacker.EquippedWeapon.AttackRollBonus) +
        ") against " + _defender.Name + "'s Armor Class: " + std::to_string(_defender.ArmorClass + _defender.EquippedWeapon.ArmorClassBonus) +
        "\n";
    std::cout << "\n";

    if (_attackRoll <= _defender.ArmorClass)
    {
        std::cout << _defender.Name + " was able to dodge the attack!\n";
    }
    else if (_attackRoll <= _defender.ArmorClass + _defender.EquippedWeapon.ArmorClassBonus)
    {
        std::cout <<
            _defender.Name + " was able to block the " + _attacker.EquippedWeapon.AttackName + " with their " +
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

    std::system("pause");
    std::cout << "\n";
}

void BattleSequence(EntityCore::Entity& _enemy, EntityCore::Entity& _player, bool _isAmbushed)
{
    if (_isAmbushed)
    {
        std::cout << "You have been ambushed!\n";
        std::cout << "\n";

        AttackSequence(_enemy, _player);
    }

    std::cout << "You are faced against a " + _enemy.Name + "!\n";
    std::cout << "\n";

    while ((_player.Health > 0) && (_enemy.Health > 0))
    {
        //Players Round
        std::cout << std::string(44, '~') + "\n";

        DisplayEntityInfo(_player);

        PlayerTurnSequence(_player, _enemy);

        //Check for Death
        if ((_player.Health <= 0) || (_enemy.Health <= 0))
            break;

        // Enemy Round
        AttackSequence(_enemy, _player);
    }

    if (_player.Health <= 0)
    {
        std::cout << _player.Name + " has been defeated..";
    }
    else if (_enemy.Health <= 0)
    {
        std::cout << _enemy.Name + " has been defeated..";
    }
}