#pragma once
#include "Piece.h"
class Pawn : public Piece
{
public:
	Pawn(std::string name, std::string location); // initiate Piece
	bool validMove(std::string dst, Board board) override;
};

