#include "Knight.h"

Knight::Knight(const char piece, const Loc& loc) : Piece(piece, loc)
{

}

bool Knight::validMove(Piece* arr[8][8], const Loc& dst) const
{
	Loc src = this->_loc;
	if (abs(dst.row - src.row) + abs(dst.col - src.col) != 3 || dst.row == src.row || dst.col == src.col) { return false; }
	return true;
}