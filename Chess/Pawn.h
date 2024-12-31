#pragma once

#include "Piece.h"


class Pawn : public Piece
{
public:
	Pawn(const char piece, const Loc& loc);
	virtual bool validMove(Piece* arr[8][8], const Loc& dst) const override;
};