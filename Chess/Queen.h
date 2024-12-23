#pragma once
#include "Piece.h"
class Queen : public Piece
{
public:
	Queen(const char piece, const Loc& loc);
	virtual bool validMove(const Board& board, const std::string& dst) const override;
};
