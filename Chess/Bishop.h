#pragma once
#include "Piece.h"
class Bishop : public Piece
{
public:
	Bishop(std::string name, std::string location); // initiate Piece
	bool validMove(std::string dst, Board board) override;
};

