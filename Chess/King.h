#pragma once

#include "Piece.h"


class King : public Piece
{
public:
	King(const char piece, const Loc& loc);
	virtual bool validMove(Piece* arr[8][8], const Loc& dst) const override;
};