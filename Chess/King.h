#pragma once
#include "Piece.h"
class King : public Piece
{
public:
	King(std::string name, std::string location); // initiate Piece
	bool validMove(std::string dst, Board board) override;
private:
	bool isChecked(Board board);
	bool isMated(Board board);
};

