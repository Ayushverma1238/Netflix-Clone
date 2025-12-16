#pragma once
#include "observer.hpp"
#include<iostream>

class ConsoleNotifier :public IObserver{
    public:
    void update(string msg){
        cout << "[NOTIFICATION] : " << msg << endl;
    }
};