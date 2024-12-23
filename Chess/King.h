#pragma once
#include "Piece.h"
class King : public Piece
{
public:
	King(const char piece, const Loc& loc);
	virtual bool validMove(const Board& board, const std::string& dst) const override;
private:
	bool isChecked(Board board);
	bool isMated(Board board);
};
