#pragma once
// #include<iostream>
#include<map>
#include<string>
// #include<vector>
#include "NotificationObserver.hpp"

class NotificationStrategy{
    protected:
    map<string, NotificationObserver*>observer;
    static NotificationStrategy * instance;
    
    public:
    static NotificationStrategy * getInstance(){
        if(!instance){
            instance = new NotificationStrategy();
        }
        return instance;
    }

    ~NotificationStrategy(){
        delete instance;
    }

    void registerObserver (string userId, NotificationObserver * observers){
        if(observer.find(userId) == observer.end()){
            observer[userId] = observers;
        }
    }

    void removeObserver(string userId){
        try
        {
            observer.erase(userId);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << "UserId cannot exist."<< '\n';
        }
    }

    void notifyUser(const string&userId, const string & message) {
        if(observer.find(userId) != observer.end()){
            observer[userId]->update(message);
        }
    }

    void notifyAll(const string & msg){
        for(auto& user : observer){
            user.second->update(msg);
        }
    }
};

NotificationStrategy * NotificationStrategy :: instance = nullptr;
