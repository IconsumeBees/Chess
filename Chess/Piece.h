#pragma once
#include <iostream>
#include "Board.h"

class Board;
class Piece
{
private:
	std::string name;
	std::string location;
public:
	Piece(std::string name, std::string location);
	virtual bool validMove(const std::string& dst, const Board& Board) const = 0;
};