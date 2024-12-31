#include "Pawn.h"



Pawn::Pawn(const char piece, const Loc& loc) : Piece(piece, loc)
{
}

bool Pawn::validMove(Piece* arr[8][8], const Loc& dst) const
{
	Loc src = this->_loc;
	bool isFirst = (std::isupper(this->_piece) && src.row == 1) || (!std::isupper(this->_piece) && src.row == 6);
	if (abs(dst.row - src.row) > 2) { return false; }
	if (dst.col != src.col && (arr[dst.row][dst.col] == nullptr)) { return false; }
	if (!isFirst && dst.row - src.row != 1) { return false; }
	return true;
}