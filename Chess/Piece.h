#pragma once

#include "iostream"
#include "cmath"
#include "Loc.h"


class Piece
{
public:
	Piece(const char piece, const Loc& loc);
	char getChar() const;
	Loc getLoc() const;
	void setLoc(const Loc& loc);
	virtual bool validMove(Piece* arr[8][8], const Loc& dst) const = 0;

protected:
	char _piece;
	Loc _loc;
};