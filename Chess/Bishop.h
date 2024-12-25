#pragma once

#include "Piece.h"


class Bishop : public Piece
{
public:
	Bishop(const char piece, const Loc& loc);
	virtual bool validMove(Piece* arr[8][8], const Loc& dst) override;
};