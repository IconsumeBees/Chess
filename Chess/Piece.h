#pragma once

#include "iostream"
#include "Loc.h"


class Piece
{
public:
	Piece(const char piece, const Loc& loc);
	char getChar() const;
	virtual bool validMove(const Piece* arr[8][8], const std::string& dst) const = 0;

private:
	char _piece;
	Loc _loc;
};