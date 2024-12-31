#include "Knight.h"
/*
c'tor for knight inherits from piece
*/
Knight::Knight(const char piece, const Loc& loc) : Piece(piece, loc)
{

}
/*
checks valid movement for knight
input:
arr -> array of the board
dst -> destination of the knight
*/
bool Knight::validMove(Piece* arr[8][8], const Loc& dst) const
{
	Loc src = this->_loc;
	if (abs(dst.row - src.row) + abs(dst.col - src.col) != 3 || dst.row == src.row || dst.col == src.col) { return false; }
	return true;
}