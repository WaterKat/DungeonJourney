#pragma once

namespace EntityCore
{
    class StatInfo
    {
    public:
        int Value = 10;
        int GetModifier()
        {
            return ((Value - 10) / 2);
        }
    };
}