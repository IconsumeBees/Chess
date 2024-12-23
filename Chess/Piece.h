#pragma once
#include <iostream>
#include <string>
#include "Board.h"
class Piece
{
public:
	std::string name;
	std::string location;
	Piece(std::string name, std::string location);
	bool validMove(std::string dst, board Board&) = 0;
};

