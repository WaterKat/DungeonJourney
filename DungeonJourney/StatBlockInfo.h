#pragma once

#include "StatInfo.h"

namespace EntityCore
{
    class StatBlockInfo
    {
    public:
        StatInfo Str;
        StatInfo Dex;
        StatInfo Con;
        StatInfo Int;
        StatInfo Wis;
        StatInfo Cha;

        StatInfo operator[](int _index)
        {
            switch (_index)
            {
            case 0:
                return Str;
                break;
            case 1:
                return Dex;
                break;
            case 2:
                return Con;
                break;
            case 3:
                return Int;
                break;
            case 4:
                return Wis;
                break;
            case 5:
                return Cha;
                break;
            default:
                return Str;
                break;
            }
        }

        void SetValues(int _str, int _dex, int _con, int _int, int _wis, int _cha)
        {
            Str.Value = _str;
            Dex.Value = _dex;
            Con.Value = _con;
            Int.Value = _int;
            Wis.Value = _wis;
            Cha.Value = _cha;
        }
    };
}