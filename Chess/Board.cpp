
#include "Board.h"
/*
c'tor for board
input :
piecesStr -> the board represented by a string 
code -> a boolean representing if black starts or not 
*/
Board::Board(const std::string& piecesStr, const char code)
{
	if (code == '0')
	{
		this->_blackMoves = false;
	}
	else
	{
		this->_blackMoves = true;
	}
	unsigned int i = 0;
	for (int row = 0; row < 8; row++)
	{
		for (int col = 0; col < 8; col++)
		{
			this->_board[row][col] = this->_newPiece(piecesStr[i], Loc{ row, col });
			i++;
		}
	}
	// the board is now represented as a 2d array of piece pointers (or nullptrs)
}

/*
d'tor for board
*/
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

/*
	checks if the piece in the current location can move the way the user wants it to, returns status codes accordingly.
input:
	src -> source location (rows and cols) 
	dst -> destination location (rows and cols)
output:
	int representing a status code according to the movement requested by the user
*/
int Board::tryMove(const Loc& src, const Loc& dst)
{
	if (int ans = this->checkInput(src, dst)) { return ans; }
	if (!this->_board[src.row][src.col]->validMove(this->_board, dst)) { return 6; } // make sure path is valid and not blocked

	Piece* dstPtr = this->_board[dst.row][dst.col];
	this->_board[dst.row][dst.col] = this->_board[src.row][src.col];
	this->_board[dst.row][dst.col]->setLoc(dst);
	this->_board[src.row][src.col] = nullptr;

	Piece* kingPtr = nullptr;
	if (this->_blackMoves) { kingPtr = this->_k_b; }
	else { kingPtr = this->_K_w; }

	if (this->_isThreatend(kingPtr))
	{
		this->_board[src.row][src.col] = this->_board[dst.row][dst.col];
		this->_board[src.row][src.col]->setLoc(src);
		this->_board[dst.row][dst.col] = dstPtr;
		return 4;
	}

	if (dstPtr != nullptr) { delete dstPtr; }
	this->_blackMoves = !this->_blackMoves;
	return 0;
}

/*
converts the board from a 2d array of piece pointers into a string.
output:
the board string (wow).
*/
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
/*
checks if the user entered a valid input to move the piece into
input:
	src -> source location (rows and cols)
	dst -> destination location (rows and cols)
output:
	int representing a status code according to the movement requested by the user
*/
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
/*
creates a new piece pointer based on parameters
input:
	piece -> name of piece
	loc -> location of the piece to create
output:
	pointer to a new piece.
*/
Piece* Board::_newPiece(const char piece, const Loc& loc)
{
	switch (piece)
	{
	case 'R':
	case 'r':
		return new Rook(piece, loc);
		break;
	case 'N':
	case 'n':
		return new Knight(piece, loc);
		break;
	case 'B':
	case 'b':
		return new Bishop(piece, loc);
		break;
	case 'Q':
	case 'q':
		return new Queen(piece, loc);
		break;
	case 'P':
	case 'p':
		return new Pawn(piece, loc);
		break;
	case 'K':
		if (this->_K_w == nullptr)
		{
			this->_K_w = new King(piece, loc);
			return this->_K_w;
			break;
		}
		else { std::cout << "there can't be multiple white kings"; }
	case 'k':
		if (this->_k_b == nullptr)
		{
			this->_k_b = new King(piece, loc);
			return this->_k_b;
			break;
		}
		else { std::cout << "there can't be multiple black kings"; }
	default:
		return nullptr;
	}
}
/*
checks if the king is threatened (the check part of checkmate)
input:
	king -> the king to check for threats
output:
	boolean based on functionality.
*/
bool Board::_isThreatend(const Piece* king)
{
	Loc square = king->getLoc();
	for (int row = 0; row < 8; row++)
	{
		for (int col = 0; col < 8; col++)
		{
			if (this->_board[row][col] != nullptr && this->_board[row][col] != king)
			{
				if (std::isupper(this->_board[row][col]->getChar()) != std::isupper(king->getChar()))
				{
					if (this->_board[row][col]->validMove(this->_board, square))
					{
						std::cout << "threat: " << locToStr(this->_board[row][col]->getLoc()) << "\n";
						return true;
					}
				}
			}
		}
	}
	return false;
}