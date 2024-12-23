#pragma once

#include "Piece.h"


class Rook : public Piece
{
public:
	Rook(const char piece, const Loc& loc);
	virtual bool validMove(const Piece* arr[8][8], const std::string& dst) const;
};