#pragma once
#include "Piece.h"
class Piece;
class Board
{
public:
    Board();
    const Piece& getPiece(const std::string& loc);
    
private:
    Piece* board[8][8];
};

