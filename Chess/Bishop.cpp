#include "Bishop.h"

Bishop::Bishop(const char piece, const Loc& loc) : Piece(piece, loc)
{

}

bool Bishop::validMove(Piece* arr[8][8], const Loc& dst) const
{
	Loc src = this->_loc;
	if (abs(src.row - dst.row) != abs(src.col - dst.col)) { return false; }
	int row, col, dstRow, dstCol, dCol;
	if (src.row < dst.row)
	{
		row = src.row;
		col = src.col;
		dstRow = dst.row;
		dstCol = dst.col;
	}
	else
	{
		row = dst.row;
		col = dst.col;
		dstRow = src.row;
		dstCol = src.col;
	}
	dCol = 0 < dstCol - col ? 1 : -1;

	col += dCol;
	for (row++; row < dstRow; row++)
	{
		if (arr[row][col] != nullptr) { return false; }
		col += dCol;
	}
	return true;
}