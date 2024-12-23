#pragma once
#include "Piece.h"
class Rook : public Piece
{
public:
	Rook(std::string name, std::string location); // initiate Piece
	bool validMove(std::string dst, Board board) override;
};

