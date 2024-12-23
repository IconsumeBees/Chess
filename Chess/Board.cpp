#include "Board.h"
Board::Board()
{
	int rows = 8, cols = 8;
	for (int i = 0; i < rows; ++i) 
	{
		this-> board[i] = new Piece[cols];
	}
}

const Piece& Board::getPiece(std::string location)
{
	// TODO: insert return statement here
}

void Board::organizeBoard()
{
}
