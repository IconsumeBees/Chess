#include "Rook.h"

/*
c'tor for rook inherits from piece
*/
Rook::Rook(const char piece, const Loc& loc) : Piece(piece, loc)
{
}

/*
checks valid movement for rook
input:
arr -> array of the board
dst -> destination of the rook
*/
bool Rook::validMove(Piece* arr[8][8], const Loc& dst) const
{
	Loc src = this->_loc;
	if (src.row == dst.row)
	{
		int start = src.col, end = dst.col;
		if (dst.col < src.col) { start = dst.col; end = src.col; }
		for (int i = start + 1; i < end; i++)
		{
			if (arr[src.row][i] != nullptr) { return false; }
		}
	}
	else if (src.col == dst.col)
	{
		int start = src.row, end = dst.row;
		if (dst.row < src.row) { start = dst.row; end = src.row; }
		for (int i = start + 1; i < end; i++)
		{
			if (arr[i][src.col] != nullptr) { return false; }
		}
	}
	else { return false; }
	return true;
}