#pragma once

#include "Piece.h"


class Rook : public Piece
{
public:
	Rook(const char piece, const Loc& loc);
	virtual bool validMove(Piece* arr[8][8], const Loc& dst) const override;
};