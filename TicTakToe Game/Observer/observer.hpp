#pragma once
#include<string>

using namespace std;

class IObserver{
    public:
    virtual void update(string msg) {};
    virtual ~IObserver(){};
};