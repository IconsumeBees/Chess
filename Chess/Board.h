
#pragma once

#include "iostream"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"
#include "Pawn.h"
#include "Loc.h"

class Board
{
public:
	Board(const std::string& piecesStr, const char code);
	~Board();
	int tryMove(const Loc& src, const Loc& dst);
	std::string getBoardStr() const;
	int checkInput(const Loc& src, const Loc& dst);
private:
	bool _isMated(const Piece* king);
	void _promote();
	Piece* _K_w = nullptr;
	Piece* _k_b = nullptr;
	Piece* _newPiece(const char piece, const Loc& loc);
	bool _isThreatend(const Piece* king);
	bool _blackMoves;
	Piece* _board[8][8];
};