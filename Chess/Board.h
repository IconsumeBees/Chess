#pragma once
#include "Piece.h"
class Board
{
public:
    Board();
    const Piece& getPiece(std::string location);
    void organizeBoard();
private:
    Piece** board;
};

