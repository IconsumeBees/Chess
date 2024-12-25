#pragma once

#include "iostream"

class Loc
{
public:
    int row;
    int col;
    bool operator==(const Loc& other) const;
    bool isValidIndex() const;
};

Loc strToLoc(const std::string str);
std::string locToStr(const Loc& loc);