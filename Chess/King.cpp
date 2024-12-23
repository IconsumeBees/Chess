#include "King.h"

King::King(std::string name, std::string location) : Piece(name, location)
{
}

bool King::isChecked(Board board)
{
	return false;
}

bool King::isMated(Board board)
{
	return false;
}
