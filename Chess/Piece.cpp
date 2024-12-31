#include "Piece.h"

Piece::Piece(const char piece, const Loc& loc)
{
	this->_piece = piece;
	this->_loc = loc;
}

char Piece::getChar() const
{
	return this->_piece;
}

Loc Piece::getLoc() const
{
	return this->_loc;
}

void Piece::setLoc(const Loc& loc)
{
	this->_loc = loc;
}