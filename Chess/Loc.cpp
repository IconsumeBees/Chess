#include "Loc.h"

Loc strToLoc(const std::string str)
{
    Loc location;
    location.col = (tolower(str[0]) - 'a') + 1;
    location.row = str[1] - '0';
    return location;
}

std::string locToStr(const Loc& loc)
{
    Loc loc;
    char letter = 'a' + (loc.col - 1);
    char number = '0' + loc.row;
    return std::string(1, letter) + number;
}

bool isValidIndex(const Loc& loc)
{
    if (loc.row > 7 || loc.row < 0 && loc.col > 7 || loc.col < 0)
    {
        return true;
    }
    return false;
}