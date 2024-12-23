#pragma once
#include "Piece.h"
class Bishop : public Piece
{
public:
	Bishop(const std::string& name, const std::string& location); // initiate Piece
	virtual bool validMove(const std::string& dst, const Board& Board) const override;
};

