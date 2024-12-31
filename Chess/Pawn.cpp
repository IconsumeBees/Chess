#include "Pawn.h"


/*
c'tor for pawn inherits from piece
*/
Pawn::Pawn(const char piece, const Loc& loc) : Piece(piece, loc)
{
}

/*
checks valid movement for pawn
input:
arr -> array of the board
dst -> destination of the pawn
*/
bool Pawn::validMove(Piece* arr[8][8], const Loc& dst) const
{
    Loc src = this->_loc;
    if (2 < abs(dst.row - src.row) || 1 < abs(dst.col - src.col )) { return false; }

    bool isFirst = (std::isupper(this->_piece) && src.row == 6) || (!std::isupper(this->_piece) && src.row == 1 );

    if (std::isupper(this->_piece) == dst.row > src.row) { return false; }

    if (!isFirst && abs(dst.row - src.row) != 1) { return false; }

    if (arr[dst.row][dst.col] != nullptr && abs(dst.col - src.col) == 0) { return false; }

    if (arr[dst.row][dst.col] == nullptr && abs(dst.col - src.col) != 0) { return false; }

    return true;
}