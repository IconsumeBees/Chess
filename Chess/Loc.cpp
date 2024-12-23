#include "Loc.h"

Loc strToLoc(const std::string str)
{
    Loc location;
    location.row = (tolower(str[0]) - 'a') + 1;
    location.col = str[1] - '0';
    return location;
}

std::string locToStr(const Loc& loc)
{
    Loc loc;
    char letter = 'a' + (loc.row - 1);
    char number = '0' + loc.col;
    return std::string(1, letter) + number;
}