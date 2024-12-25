
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

int Board::tryMove(const Loc& src, const Loc& dst)
{
	if (int ans = this->checkInput(src, dst)) { return ans; }
	if (!this->_board[src.row][src.col]->validMove(this->_board, dst)) { return 6; } // make sure path is valid and not blocked

	this->_board[dst.row][dst.col] = this->_board[src.row][src.col];
	this->_board[src.row][src.col]->setLoc(dst);
	this->_board[src.row][src.col] = nullptr;
	this->_blackMoves = !this->_blackMoves;
	return 0;
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

int Board::checkInput(const Loc& src, const Loc& dst)
{
	if (src == dst) { return 7; } // make sure src and dst are not the same
	if (!(src.isValidIndex() && dst.isValidIndex())) { return 5; } // make sure src and dst are on the board
	if (this->_board[src.row][src.col] == nullptr) { return 2; } // make sure src is not empty
	if (std::isupper(this->_board[src.row][src.col]->getChar()) == this->_blackMoves) { return 2; } // make sure the player has a piece in src
	if (this->_board[dst.row][dst.col] != nullptr)
	{
		if (std::isupper(this->_board[dst.row][dst.col]->getChar()) != this->_blackMoves) { return 3; } // make sure the player doesn't have a piece in dst
	}

	return 0;
}

Piece* Board::_newPiece(const char piece, const Loc& loc)
{
	switch (piece)
	{
	case 'R':
	case 'r':
		return new Rook(piece, loc);
		break;
	case 'K':
	case 'k':
		return new King(piece, loc);
		break;
	default:
		return nullptr;
	}
}