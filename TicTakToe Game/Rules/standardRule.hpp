#pragma once
#include "rule.hpp"

class StandardRule :public IRule
{
public:
    bool isValidMove(Board *grid, int r, int c) override
    {
        if (!grid->isCellEmpty(r, c))
        {
            return false;
        }
        return true;
    }

    bool checkWin(Board *grid, Symbol *s) override
    {
        int size = grid->getSize();
        // row
        for (int i = 0; i < size; i++)
        {
            bool isWinner = true;
            for (int j = 0; j < size; j++)
            {
                if (grid->getCell(i,j) != s)
                {
                    isWinner = false;
                }
            }
            if (isWinner)
            {
                return true;
            }
        }
        // column
        for (int i = 0; i < size; i++)
        {
            bool isWinner = true;
            for (int j = 0; j < size; j++)
            {
                if (grid->getCell(j, i) != s)
                {
                    isWinner = false;
                }
            }
            if (isWinner)
            {
                return true;
            }
        }

        // diagonally
        int i = 0, j = 0;
        bool isWinner = true;
        while (i < size && j < size)
        {
            if (grid->getCell(i,j) != s)
            {
                isWinner = false;
            }
            i++;j++;
        }
        if (isWinner)
        {
            return true;
        }
        //anti diagonally
        i = 0;j = size-1;
        isWinner = true;
        while(i < size && j >=0 ){
            if(grid->getCell(i,j) != s){
                isWinner = false;
            }
            i++;j--;
        }
        if (isWinner)
        {
            return true;
        }   

        return false;
    }
    bool checkDraw(Board * grid) override{
        int size = grid->getSize();
        for(int i= 0; i < size; i++){
            for(int j = 0;j < size; j++){
                if(grid->getCell(i, j) == grid->getEmptySymbol()){
                    return false;
                }
            }
        }
        return true;
    }
};