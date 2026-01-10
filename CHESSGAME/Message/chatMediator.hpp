#pragma once
#include "message.hpp"
class User;
class ChatMediator{
    public:
    virtual void send(Message * msg, User * user) =0;
    virtual void addUser(User * user) = 0;
    virtual void removeUser(User * user) =0;
    virtual ~ChatMediator(){};
};