#include "Loc.h"

/*
function converts string of location (e.g e2) into loc (rows and cols)
input:
str -> the location string
*/
Loc strToLoc(const std::string str)
{
    return Loc{ 7 - (str[1] - '1'), str[0] - 'a' };
}

/*
function converts loc (rows and cols) into string of location (e.g e2)
input:
loc -> the location value (rows and cols0
*/
std::string locToStr(const Loc& loc)
{
    char col = loc.col + 'a';
    return std::string(1, col) + std::to_string(8 - loc.row);
}

/*
function overloads the operator == to returns a boolean value if the two locations are the same
input:
other -> the location you want to compare to. 
output: 
boolean if functionality is true or false.
*/
bool Loc::operator==(const Loc& other) const
{
    return this->row == other.row && this->col == other.col;
}

/*
function checks if a location is within the bounds of the chess board.
output:
boolean if functionality is true or false.
*/
bool Loc::isValidIndex() const
{
    return 0 <= this->row && this->row <= 7 && 0 <= this->col && this->col <= 7;
}