#pragma once
#include "Piece.hpp"

class Bishop:public Piece{
    public:
    Bishop(Color c) : Piece(c, PieceType::BISHOP){}

    std::vector<Position> getPossibleMoves(Position currentPos, Board * board)const override;
    string getSymbol() const override{
        return "B";
    }
};