#include "Knight.h"

Knight::Knight(const char piece, const Loc& loc) : Piece(piece, loc)
{

}

bool Knight::validMove(Piece* arr[8][8], const Loc& dst)
{
	Loc src = this->_loc;
	if (dst.row - src.row + dst.col - src.col != 3 && dst.row - src.row != 0 && dst.row - src.row != 0) { return false; }
	return true;
}
