#pragma once

#include "Piece.h"

class Rook : public Piece
{
public:
	Rook(const char piece, const Loc& loc);
	virtual bool validMove(const Board& board, const std::string& dst) const override;
};