#pragma once

#include "iostream"
#include "Loc.h"


class Piece
{
public:
	Piece(const char piece, const Loc& loc);
	char getChar() const;
	void setLoc(const Loc& loc);
	virtual bool validMove(Piece* arr[8][8], const Loc& dst) const = 0;

protected:
	char _piece;
	Loc _loc;
};