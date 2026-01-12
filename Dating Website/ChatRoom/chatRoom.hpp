#pragma once
#include<vector>
#include<iostream>
#include "message.hpp"
#include <string>
#include<algorithm>
class ChatRoom {
    string id;
    vector<string> participantIds;
    vector<Message*>message;
    public:
    ChatRoom(const string & id, const string & user1, const string & user2){
        this->id = id;
        participantIds.push_back(user1);
        participantIds.push_back(user2);
    }

    ~ChatRoom(){
        for(auto msg : message){
            delete msg;
        }
        
    }

    string getId() const{
        return id;
    }
    void addMessages(const string & senderId, const string & content){
        Message * msg = new Message(senderId, content);
        message.push_back(msg);
    }

    bool hasParticipent(const string & userId) const{
        return find(participantIds.begin(), participantIds.end(), userId) != participantIds.end();
    }

    const vector<Message*> getMessage() const{
        return message;
    }

    const vector<string> getParticipated() const{
        return participantIds;
    }

    void displayChat()const{
        cout << "========ChatRoom: ====== " << id << " ====="<<endl;
        for(const auto & msg : message){
            cout << "[" << msg->getFormattadTime() << "] " << msg->getSenderId() << ": " << msg->getContent() << endl;
        }
        cout << "========================================="<<endl;
    }
};