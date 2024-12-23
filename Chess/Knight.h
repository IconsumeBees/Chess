#pragma once
#include "Piece.h"
class Knight : public Piece
{
public:
	Knight(const std::string& name, const std::string& location); // initiate Piece
	virtual bool validMove(const std::string& dst, const Board& Board) const override;
};

