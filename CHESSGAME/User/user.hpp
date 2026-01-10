#pragma once
#include<iostream>
#include "../Message/colleague.hpp"
#include "../Message/message.hpp"
using namespace std;

class User : public Colleague{
    string id;
    string name;
    int score;
    public:
    User(string id, string name){
        this->id = id;
        this->name = name;
        score = 0;
    }

    string getId() const{
        return id;
    }

    string getName() const {
        return name;
    }

    int getScore(){
        return score;
    }

    void incrementScore(int points){
        score += points;
        return;
    }

    void decrementScore(int points){
        score -= points;
        return;
    }

    string toString() const {
        return name + " (Score: " + to_string(score) + ")";
    }

    void send(Message* msg) override{
        if(m != nullptr){
            m->send(msg, this);
        }
    }

    void receive(Message * msg) override{
        cout << "User " << name << " receive message from " << msg->getSenderId() << ": "<< msg->getContent() << endl;
    }
};