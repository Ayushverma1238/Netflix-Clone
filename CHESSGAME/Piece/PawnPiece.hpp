#pragma once
#include "Piece.hpp"

class Pawn : public Piece{
    public:
    Pawn(Color c) : Piece(c, PieceType::PAWN){}
    std::vector<Position> getPossibleMoves(Position currentPos, Board * board)const override;
    string getSymbol()const override{
        return "P";
    }
};