#pragma once
# include "../symbol/symbol.hpp"
#include<string>
using namespace std;
class Player{
    int id;
    string name;
    Symbol *s;
    int score;
    public:
    Player(int id, string name, Symbol* s)
    {
        this-> id = id;
        this->name = name;
        this->s = s;
        score = 0;
    }

    int getId()const{
        return id;
    }
    string getName() const{
        return name;
    }
    Symbol * getSymbol()const{
        return s;
    }

    int getScore(){
        return score;
    }

    void incrementScore(){
        ++score;
    }

    ~Player(){
        delete s;
    };
};