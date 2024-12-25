#include "Rook.h"

Rook::Rook(const char piece, const Loc& loc) : Piece(piece, loc)
{
}

bool Rook::validMove(Piece* arr[8][8], const Loc& dst) const
{
	Loc src = this->_loc;
	if (src.row != dst.row && src.col != dst.col) 
	{ return false; }
	if (src.row == dst.row)
	{
		int start = src.col, end = dst.col;
		if (dst.col < src.col) { start = dst.col; end = src.col; }
		for (int i = start + 1; i < end; i++)
		{
			if (arr[src.row][i] != nullptr) { return false; }
		}
	}
	if (src.col == dst.col)
	{
		int start = src.row, end = dst.row;
		if (dst.row < src.row) { start = dst.row; end = src.row; }
		for (int i = start + 1; i < end; i++)
		{
			if (arr[i][src.col] != nullptr) { return false; }
		}
	}
	return true;
}