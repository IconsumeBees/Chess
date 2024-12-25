#include "Pawn.h"



Pawn::Pawn(const char piece, const Loc& loc) : Piece(piece, loc)
{
	this->isFirst = true;
}

bool Pawn::validMove(Piece* arr[8][8], const Loc& dst)
{
	Loc src = this->_loc;
	if (dst.row - src.row > 2) { return false; }
	if (dst.col != src.col && (arr[dst.row][dst.col] == nullptr)) { return false; }
	if (this->isFirst == false && dst.row - src.row != 1) { return false; }
	this->isFirst = false;
	return true;
}

