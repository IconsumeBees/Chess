
#include "Board.h"

Board::Board(const std::string& piecesStr)
{
	this->_blackMoves = true;
	unsigned int i = 0;
	for (int row = 0; row < 8; row++)
	{
		for (int col = 0; col < 8; col++)
		{
			this->_board[row][col] = this->_newPiece(piecesStr[i], Loc{ row, col });
			i++;
		}
	}
}

Board::~Board()
{
	for (int row = 0; row < 8; row++)
	{
		for (int col = 0; col < 8; col++)
		{
			if (this->_board[row][col] != nullptr) { delete this->_board[row][col]; }
		}
	}
}

int Board::tryMove(const std::string& moveStr)
{
	return 1;
}

std::string Board::getBoardStr() const
{
	std::string boardStr = "";
	for (int row = 0; row < 8; row++)
	{
		for (int col = 0; col < 8; col++)
		{
			if (this->_board[row][col] == nullptr) { boardStr += "#"; }
			else { boardStr += this->_board[row][col]->getChar(); }
		}
	}
	return boardStr;
}

Piece* Board::_newPiece(const char piece, const Loc& loc)
{
	switch (piece)
	{
	case 'R':
	case 'r':
		return new Rook(piece, loc);
		break;
	defualt:
		return nullptr;
	}
}