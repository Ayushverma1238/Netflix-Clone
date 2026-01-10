#pragma once
#include "../enum/color.hpp"
#include "../enum/PieceType.hpp"
class Position;
#include<vector>
#include<iostream>
class Board;
using namespace std;

class Piece{
    public:
    Color  color;
    PieceType  pt;
    bool hasMoved;
    
    Piece(Color col, PieceType pt){
        color = col;
        this->pt = pt;
        hasMoved = false;
    }

    Color getColor() const{
        return color;
    }

    PieceType getPieceType()const{
        return pt;
    }

    bool getHasMoved() {
        return hasMoved;
    }

    void setHasMoved(bool moved){
        hasMoved = moved;
    }

    virtual vector<Position> getPossibleMoves(Position currentPos, Board* board) const = 0;
    virtual string getSymbol()const = 0;

    string toString() {
        string colorStr = (color == Color::WHITE) ? "W" : "B";
        return colorStr + getSymbol();
    }

    virtual ~Piece(){};
};