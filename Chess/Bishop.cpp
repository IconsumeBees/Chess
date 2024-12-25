#include "Bishop.h"

Bishop::Bishop(const char piece, const Loc& loc) : Piece(piece, loc)
{

}

bool Bishop::validMove(Piece* arr[8][8], const Loc& dst)
{
	Loc src = this->_loc;
	if (dst.row - src.row != dst.col - src.col) { return false; }
	int start1 = src.row, start2 = src.col, end1 = dst.row, end2 = dst.col;
	for (int i = start1 + 1; i < end1; i++)
	{
		for (int j = start2 + 1; i < end2; i++)
		{
			if (arr[i][j] != nullptr) { return false; }
		}
	}
	return true;
}