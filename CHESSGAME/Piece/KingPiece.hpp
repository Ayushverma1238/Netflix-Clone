#pragma once
#include "Piece.hpp"
#include<vector>
using namespace std;
class Board;

class King : public Piece
{
public:
    King(Color color) : Piece(color, PieceType::KING) {}

    std::vector<Position> getPossibleMoves(Position currentPos, Board *board)const override;
    string getSymbol() const override
    {
        return "K";
    }
};