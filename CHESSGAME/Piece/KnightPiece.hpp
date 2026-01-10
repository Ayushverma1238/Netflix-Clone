#pragma once
#include "Piece.hpp"

class Knight : public Piece{
    public:
    Knight(Color c) : Piece(c, PieceType::KNIGHT){}
    std::vector<Position> getPossibleMoves(Position currentPos, Board * board) const override;
    string getSymbol() const override{
        return "N";
    }
};