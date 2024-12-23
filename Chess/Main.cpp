#include "Board.h"


static void printBoard(const std::string& boardStr)
{
	unsigned int i = 0;
	for (int row = 0; row < 8; row++)
	{
		for (int col = 0; col < 8; col++)
		{
			std::cout << boardStr[i] << " ";
			i++;
		}
		std::cout << "\n";
	}
}

static int checkInput(std::string src, std::string dst, Piece* board[8][8], bool blackMoves)
{
	Loc location, destination;
	location = strToLoc(src);
	destination = strToLoc(src);
	if (location.row > 7 || location.row < 0 && location.col > 7 || location.col < 0)
	{
		return 6;
	}

	if (destination.row > 7 || destination.row < 0 && destination.col > 7 || destination.col < 0)
	{
		return 6;
	}

	if (location.row == destination.row && location.col == destination.col)
	{
		return 7;
	}
	
	if (board[location.row][location.col])
	{
		if (blackMoves)
		{
			if (!(std::islower(board[location.row][location.col]->getChar())))
			{
				return 2;
			}
			if (std::islower(board[destination.row][destination.col]->getChar()))
			{
				return 3;
			}
		}
		else
		{
			if (!(std::isupper(board[location.row][location.col]->getChar())))
			{
				return 2;
			}
			if (std::isupper(board[destination.row][destination.col]->getChar()))
			{
				return 3;
			}
		}
		return 0;
	}
}

int main()
{
	/*
	std::string piecesStr =
		"RNBQKBNR"
		"PPPPPPPP"
		"########"
		"########"
		"########"
		"########"
		"pppppppp"
		"rnbqkbnr";
	*/
	std::string piecesStr =
		"R######R"
		"########"
		"########"
		"########"
		"########"
		"########"
		"########"
		"r######r";

	Board board(piecesStr);

	std::string move = "";
	while (move != "x")
	{
		std::cout << "move: ";
		std::cin >> move;

		printBoard(board.getBoardStr());
	}

	return 0;
}