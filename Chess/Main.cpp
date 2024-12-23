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

	Board board(piecesStr); // construct board

	std::string move = "";
	while (move != "x")
	{
		std::cout << "move: ";
		std::cin >> move;

		printBoard(board.getBoardStr());
	}

	return 0;
}