#pragma once

#include "iostream"

typedef struct
{
    int row;
    int col;
} Loc;

Loc strToLoc(const std::string str);
std::string locToStr(const Loc& loc);