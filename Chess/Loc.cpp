#include "Loc.h"

Loc strToLoc(const std::string str)
{
    return Loc{ 7 - (str[1] - '1'), str[0] - 'a' };
}

std::string locToStr(const Loc& loc)
{
    char col = loc.col + 'a';
    return "" + col + loc.row;
}

bool Loc::operator==(const Loc& other) const
{
    return this->row == other.row && this->col == other.col;
}

bool Loc::isValidIndex() const
{
    return 0 <= this->row && this->row <= 7 && 0 <= this->col && this->col <= 7;
}