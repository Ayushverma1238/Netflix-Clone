#pragma once
#include "Piece.hpp"

class Rook : public Piece{
    public:
    Rook(Color c) : Piece(c, PieceType::ROOK){}

    std::vector<Position> getPossibleMoves(Position currentPos, Board * board)const override;
    string getSymbol() const override{
        return "R";
    }
};