#pragma once

#include "iostream"
#include "Loc.h"
#include "Board.h"

class Piece
{
public:
	Piece(const char piece, const Loc& loc);
	char getChar() const;
	virtual bool validMove(const Board& board, const std::string& dst) const = 0;

private:
	char _piece;
	Loc _loc;
};