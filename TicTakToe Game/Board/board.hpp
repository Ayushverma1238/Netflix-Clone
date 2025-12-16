#pragma once
#include "../symbol/symbol.hpp"

#include<iostream>
#include<vector>
using namespace std;

class Board{
    vector<vector<Symbol*>> grid;
    int size;
    Symbol * emptySymbol;

    public:
    Board(int size){
        this->size = size;
        emptySymbol = new Symbol('-');
        grid = vector<vector<Symbol*>> (size, vector<Symbol*>(size, emptySymbol));
    }
    int getSize () const{
        return size;
    }

    Symbol * getEmptySymbol(){
        return emptySymbol;
    }

    bool isCellEmpty(int r, int c){
        if(r < 0 || r >= size || c < 0 || c >= size || grid[r][c] != emptySymbol){
            return false;
        }
        return true;
    }

    bool placeMark(int r, int c, Symbol * s){
        if(!isCellEmpty(r, c)){
            return false;
        }
        grid[r][c] = s;
        return true;
    }
    
    Symbol * getCell(int r, int c){
        if(r < 0 || r >= size || c < 0 || c >= size){
            return emptySymbol;
        }
        return grid[r][c];
    }

    void display(){
        cout<<"\n==========Displaying whole Board=====\n";
        for(int i = 0; i< size; i++){
            for(int j = 0;j < size; j++){
                cout << grid[i][j]->getMark()<<" | ";

            }
            cout << "\n";
        }
    }
};