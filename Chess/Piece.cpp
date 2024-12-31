#include "Piece.h"
/*
c'tor for piece
input:
piece -> the type of piece that is to be constructed (e.g r for rook or k for king and color based on if letter upper or lower case.
loc -> location of the piece on the board.
*/
Piece::Piece(const char piece, const Loc& loc)
{
	this->_piece = piece;
	this->_loc = loc;
}
/*
returns the piece type (output)
*/
char Piece::getChar() const
{
	return this->_piece;
}
/*
returns location on the board (output)
*/
Loc Piece::getLoc() const
{
	return this->_loc;
}
/*
sets the location of the piece
input : 
loc -> location to be set.
*/
void Piece::setLoc(const Loc& loc)
{
	this->_loc = loc;
}