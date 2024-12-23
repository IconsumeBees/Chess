#include "Board.h"
Board::Board(const std::string& piecesStr)
{
	this->_boardStr = piecesStr;
	this->_blackMoves = true;
	unsigned int i = 0;
	for (int row = 0; row < 8; row++)
	{
		for (int col = 0; col < 8; col++)
		{
			this->_board[row][col] = this->_newPiece(this->_boardStr[i], Loc{ "", row, col });
			i++;
		}
	}
}

const Piece& Board::getPiece(std::string location)
{
	// TODO: insert return statement here
}

void Board::organizeBoard()
{
}
