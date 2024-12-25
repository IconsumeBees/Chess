#pragma once
#include "Piece.h"
class Knight : public Piece
{
public:
	Knight(const char piece, const Loc& loc);
	virtual bool validMove(Piece* arr[8][8], const Loc& dst) override;
};
