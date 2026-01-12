#pragma once

#include<iostream>
#include<map>

using namespace std;

class NotificationObserver{
    string msg;
    public:
    virtual ~NotificationObserver(){};
    virtual void update(const string& msg) = 0;
};