#include "Loc.h"

Loc strToLoc(const std::string str)
{
    return Loc{};
}

std::string locToStr(const Loc& loc)
{
    char col = loc.col + 'a';
    return "" + col + loc.row;
}