#include "Queen.h"

Queen::Queen(const char piece, const Loc& loc) : Piece(piece, loc)
{
}

bool Queen::validMove(Piece* arr[8][8], const Loc& dst)
{
	Loc src = this->_loc;
	if (dst.col != src.col && dst.row == src.row || dst.col == src.col && dst.row != src.row)
	{
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
	}
	else 
	{
		if (dst.row - src.row != dst.col - src.col) { return false; }
		int start1 = src.row, start2 = src.col, end1 = dst.row, end2 = dst.col;
		for (int i = start1 + 1; i < end1; i++)
		{
			for (int j = start2 + 1; i < end2; i++)
			{
				if (arr[i][j] != nullptr) { return false; }
			}
		}
	}
	return true;
}


