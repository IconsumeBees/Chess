#include "Rook.h"

Rook::Rook(const char piece, const Loc& loc) : Piece(piece, loc)
{
}

bool Rook::validMove(const Piece* arr[8][8], const std::string& dst) const
{
	return false;
}