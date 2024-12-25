
#pragma once

#include "iostream"
#include "Rook.h"
#include "Loc.h"

class Board
{
public:
	Board(const std::string& piecesStr);
	~Board();
	int tryMove(const Loc& src, const Loc& dst);
	std::string getBoardStr() const;
private:
	Piece* _newPiece(const char piece, const Loc& loc);

	bool _blackMoves;
	Piece* _board[8][8];
};