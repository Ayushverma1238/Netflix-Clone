#pragma once
#include "Piece.hpp"

class Queen : public Piece{
    public:
    Queen (Color c) : Piece(c, PieceType::QUEEN){}

    std::vector<Position> getPossibleMoves(Position currentPos, Board * board) const override;
    string getSymbol() const override{
        return "Q";
    }
};
