#include "Board.h"
#include <windows.h>

static void coloredOut(const std::string& str, const int color)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
	std::cout << str;
	SetConsoleTextAttribute(hConsole, 7);
}

static void printBoard(const std::string& boardStr)
{
	unsigned int i = 0;
	for (int row = 0; row < 8; row++)
	{
		coloredOut(std::to_string(8 - row) + " ", 1);
		for (int col = 0; col < 8; col++)
		{
			std::cout << boardStr[i] << " ";
			i++;
		}
		std::cout << "\n";
	}
	coloredOut("  a b c d e f g h\n", 1);
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
		"R##Kk###"
		"########"
		"########"
		"########"
		"r######r";

	Board board(piecesStr);

	std::string move = "";
	while (move != "x")
	{
		printBoard(board.getBoardStr());
		std::cout << "move: ";
		std::cin >> move;
		Loc src = strToLoc(move.substr(0, 2));
		Loc dst = strToLoc(move.substr(2));
		//std::cout << src.row << ", " << src.col << "\n" << dst.row << ", " << dst.col << "\n";

		std::cout << board.tryMove(src, dst) << "\n";
	}



	return 0;
}