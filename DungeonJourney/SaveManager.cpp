#include "SaveManager.h"

void SaveManager::SaveToSlot(WorldInfo& _worldInfo, int _saveSlot)
{
    std::ofstream _fileStream;

    _fileStream.open("save_" + std::to_string(_saveSlot) + ".save", std::ios::app);
    _fileStream.clear();
    _fileStream.write((char*)&_worldInfo, sizeof(_worldInfo));
    _fileStream.close();
}

WorldInfo SaveManager::LoadFromSlot(int _saveSlot)
{
    std::ifstream _fileStream;

    _fileStream.open("save_" + std::to_string(_saveSlot) + ".save", std::ios::app);

    WorldInfo _worldInfo;
    _fileStream.read((char*)&_worldInfo,sizeof(_worldInfo));
    _fileStream.close();
    return _worldInfo;
}