#pragma once
#include "Piece.h"
class Knight : public Piece
{
public:
	Knight(std::string name, std::string location); // initiate Piece
	bool validMove(std::string dst, Board board) override;
};

