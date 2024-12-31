#include "Queen.h"
#include "Rook.h"
#include "Bishop.h"

Queen::Queen(const char piece, const Loc& loc) : Piece(piece, loc)
{
}

bool Queen::validMove(Piece* arr[8][8], const Loc& dst) const
{
	Loc src = this->_loc;
	Piece* tempPiece = nullptr;
	if (src.row == dst.row || src.col == dst.col)
	{
		tempPiece = new Rook('x', src);
		return tempPiece->validMove(arr, dst);
	}
	if (abs(src.row - dst.row) == abs(src.col - dst.col))
	{
		tempPiece = new Bishop('x', src);
		return tempPiece->validMove(arr, dst);
	}
	return false;
}