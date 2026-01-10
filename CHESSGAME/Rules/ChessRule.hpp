#pragma once
#include "../Moves/Move.hpp"
#include "../enum/color.hpp"
#include "../Board/board.hpp"

class ChessRule{
    public:
    ChessRule(){}
    virtual bool isValidMove(Move m, Board * b) =0;
    virtual bool isInCheck(Color c, Board * b) = 0;
    virtual bool isCheckMate(Color c, Board * b) = 0;
    virtual bool isStaleMate(Color c, Board * b) = 0;
    virtual bool wouldCauseCheck(Move m, Board * b, Color c)= 0;
    virtual ~ChessRule(){};
};