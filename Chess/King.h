#pragma once
#include "Piece.h"
class King : public Piece
{
public:
	King(const std::string& name, const std::string& location); // initiate Piece
	virtual bool validMove(const std::string& dst, const Board& Board) const override;
private:
	bool isChecked(const Board& board) const;
	bool isMated(const Board& board) const;
};

