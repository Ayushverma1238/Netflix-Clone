#pragma once
#include "../Board/board.hpp"
#include "../symbol/symbol.hpp"

using namespace std;

class IRule{
    public:
    // IRule(){};
    virtual bool isValidMove(Board * grid, int r, int c)  = 0;
    virtual bool checkWin(Board * grid, Symbol * s) = 0;
    virtual bool checkDraw(Board * grid) =0;
    virtual ~IRule(){};

};