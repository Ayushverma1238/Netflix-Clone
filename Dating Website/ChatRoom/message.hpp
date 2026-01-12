#pragma once
#include <string>
#include<ctime>
using namespace std;

class Message{
    string senderId;
    string content;
    time_t timestamp;

    public:
    Message(const string & senderId, const string & msg){
        this->senderId = senderId;
        this->content = msg;
        timestamp = time(nullptr);
    }

    string getSenderId() const{
        return senderId;
    }

    string getContent() const{
        return content;
    }

    time_t getTimeStamp() const{
        return timestamp;
    }

    string getFormattadTime() const{
        struct tm* timeinfo;
        char buffer[80];
        timeinfo = localtime(&timestamp);
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", timeinfo);
        return string(buffer);
    }
};