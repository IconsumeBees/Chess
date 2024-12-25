#pragma once
#include "Piece.h"
class Queen : public Piece
{
public:
	Queen(const char piece, const Loc& loc);
	virtual bool validMove(Piece* arr[8][8], const Loc& dst) override;
};
