#include "King.h"

King::King(const char piece, const Loc& loc) : Piece(piece, loc)
{
}

bool King::validMove(Piece* arr[8][8], const Loc& dst) const
{
	Loc src = this->_loc;
	if (arr[src.row][src.col] == arr[dst.row][dst.col])
	{
		return false;
	}
	if (!(isValidIndex(dst)))
	{
		return false;
	}
	if (arr[src.row] == arr[dst.row] - 1 || arr[src.row] == arr[dst.row] + 1 || arr[src.row] == arr[dst.row] && arr[src.col] == arr[dst.col] - 1 || arr[src.col] == arr[dst.col] + 1 || arr[src.col] == arr[dst.col])
	{
		return true;
	}
	return false;
}