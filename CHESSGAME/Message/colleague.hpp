#pragma once
#include "chatMediator.hpp"

class Colleague{
    protected:
    ChatMediator * m;
    public:
    Colleague () : m(nullptr){};
    virtual void send(Message * msg) = 0;
    virtual void receive(Message* msg) = 0;
    virtual void setMediator(ChatMediator * m){
        this->m = m;

    }
    ChatMediator * getMediator() {
        return m;
    }

};