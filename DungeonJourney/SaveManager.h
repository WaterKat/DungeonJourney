#pragma once

#include <fstream>
#include "WorldInfo.h"

class SaveManager
{
public:
	void SaveToSlot(WorldInfo& _worldInfo, int _saveSlot);
	WorldInfo LoadFromSlot(int _saveSlot);
};

