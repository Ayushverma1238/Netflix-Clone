#pragma once

class Symbol{
    char mark;
    public:
    
    Symbol(char mark){
        this->mark = mark;
    }

    char getMark() const{
        return mark;
    }
};
