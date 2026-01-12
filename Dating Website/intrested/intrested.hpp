#pragma once

#include<string>
using namespace std;
class Intreseted{
    string name;
    string category;

    public:
    Intreseted(){
        this->name = "";
        this->category = "";
    }

    Intreseted(string name, string category){
        this->name = name;
        this->category = category;
    }

    string getName() const{
        return name;
    }
    string getCategory() const{
        return category;
    }

};