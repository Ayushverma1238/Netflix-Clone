#pragma once
#include <iostream>
// #include<TimeUtils.h>
using namespace std;

class Message{
    string senderId;
    string content;
    time_t timeStamp;
    public:
    Message(string senderId, string content){
        this->senderId = senderId;
        this->content= content;
        timeStamp = time(0);
    }

    string getSenderId()const{
        return senderId;
    }

    string getContent() const{
        return content;
    }

    time_t getTimeStamp() const {
        return timeStamp;
    }

    string toString(){
        return "[" + senderId + "]: " + content ;
    }
};