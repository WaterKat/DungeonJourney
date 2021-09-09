#include <iostream>

#include "Entity.h"
#include "DiceRolls.h"

void DisplayEntityInfo(EntityCore::Entity _entity);

int PromptChoice(std::string _preMessage, std::string _textOptions[], int _textOptionsLength);

void PlayerTurnSequence(EntityCore::Entity& _player, EntityCore::Entity& _enemy);

void AttackSequence(EntityCore::Entity& _attacker, EntityCore::Entity& _defender);

void BattleSequence(EntityCore::Entity& _enemy, EntityCore::Entity& _player, bool _isAmbushed);