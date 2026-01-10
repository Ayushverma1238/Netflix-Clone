#pragma once
#include<iostream>
using namespace std;
class Position{
    int row;
    int col;

public:
    Position(){
        row = 0;
        col = 0;
    }

    // INTERNAL USE (array indices)
    Position(int r, int c){
        row = r;
        col = c;
    }

    // ✅ CHESS COORDINATES (THIS IS THE FIX)
    Position(char file, int rank){
        col = file - 'a';     // a-h → 0-7
        row = 8 - rank;       // 1-8 → 7-0
    }

    int getRow() const { return row; }
    int getCol() const { return col; }

    bool isValidMove() const{
        return row >= 0 && row < 8 && col >= 0 && col < 8;
    }

    bool operator==(const Position& other) const{
        return row == other.row && col == other.col;
    }

    bool operator<(const Position& other) const{
        if(row != other.row) return row < other.row;
        return col < other.col;
    }

    string toString() const{
        return "(" + to_string(row) + ", " + to_string(col) + ")";
    }

    string toChessNotation() const{
        char file = 'a' + col;
        int rank = 8 - row;
        return string(1, file) + to_string(rank);
    }
};
