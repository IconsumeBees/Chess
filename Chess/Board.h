
#pragma once

#include "iostream"
#include "Rook.h"
#include "Loc.h"
class Piece;

class Board
{
public:
	Board(const std::string& piecesStr);
	~Board();
	int tryMove(const std::string& moveStr);
	std::string getBoardStr() const;
private:
	Piece* _newPiece(const char piece, const Loc& loc);

	bool _blackMoves;
	Piece* _board[8][8];
};