#include "King.h"
/*
c'tor for king inherits from piece
*/
King::King(const char piece, const Loc& loc) : Piece(piece, loc)
{
}

/*
checks valid movement for king
input: 
arr -> array of the board
dst -> destination of the king
*/
bool King::validMove(Piece* arr[8][8], const Loc& dst) const
{
	if (!(this->_loc.row - 1 <= dst.row && dst.row <= this->_loc.row + 1)) { return false; }
	if (!(this->_loc.col - 1 <= dst.col && dst.col <= this->_loc.col + 1)) { return false; }
	return true;
}