#pragma once
#include "Piece.h"
class Knight : public Piece
{
public:
	Knight(const char piece, const Loc& loc);
	virtual bool validMove(const Board& board, const std::string& dst) const override;
};
