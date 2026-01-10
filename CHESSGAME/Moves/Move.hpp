#pragma once
#include "Position.hpp"
#include"../Piece/Piece.hpp"
class Move{
    Position from;
    Position to;
    Piece *piece;
    Piece *captured;
    public:
    Move(){
        piece = nullptr;
        captured = nullptr;
    }

    Move(Position f, Position t, Piece * p, Piece * cap){
        this->from = f;
        to = t;
        piece = p;
        captured = cap;
    }

    Position getFrom() const{
        return from;
    }

    Position getTo() const{
        return to;
    }

    Piece * getPiece() const{
        return piece;
    }

    Piece * getCapturedPiece() const {
        return captured;
    }
};