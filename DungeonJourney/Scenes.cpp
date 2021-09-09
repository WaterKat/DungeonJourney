#include "Scenes.h"

#include "GameMechanics.h"

using namespace Scenes;

int Menu(WorldInfo& _worldInfo)
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