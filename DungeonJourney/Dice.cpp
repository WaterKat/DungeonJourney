#include "DiceRolls.h"

#include <stdlib.h>

int Dice::RollD20()
{
	return rand() % 20 + 1;
}

int Dice::RollD12()
{
	return rand() % 12 + 1;
}

int Dice::RollD10()
{
	return rand() % 10 + 1;
}

int Dice::RollD8()
{
	return rand() % 8 + 1;
}

int Dice::RollD6()
{
	return rand() % 6 + 1;
}

int Dice::RollD4()
{
	return rand() % 4 + 1;
}
