#pragma once

#include "Piece.h"

class Bishop : public Piece
{
public:
	Bishop(const char piece, const Loc& loc);
	virtual bool validMove(const Board& board, const std::string& dst) const override;
};