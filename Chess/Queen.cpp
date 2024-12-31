#include "Queen.h"
#include "Rook.h"
#include "Bishop.h"
/*
c'tor for queen inherits from piece
*/
Queen::Queen(const char piece, const Loc& loc) : Piece(piece, loc)
{
}

/*
checks valid movement for queen
input:
arr -> array of the board
dst -> destination of the queen
*/
bool Queen::validMove(Piece* arr[8][8], const Loc& dst) const
{
	Loc src = this->_loc;
	bool ret = false;
	Piece* tempPiece = nullptr;
	if (src.row == dst.row || src.col == dst.col)
	{
		tempPiece = new Rook('x', src);
		ret = tempPiece->validMove(arr, dst);
		delete(tempPiece);
		return ret;
	}
	if (abs(src.row - dst.row) == abs(src.col - dst.col))
	{
		tempPiece = new Bishop('x', src);
		ret = tempPiece->validMove(arr, dst);
		delete(tempPiece);
		return ret;
	}
	return false;
}