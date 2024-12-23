#pragma once
#include "Piece.h"
class Queen : public Piece
{
public:
	Queen(std::string name, std::string location); // initiate Piece
	bool validMove(std::string dst, Board board) override;
};

