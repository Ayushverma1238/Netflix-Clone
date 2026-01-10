#pragma once
#include "../User/user.hpp"
#include<vector>
class MatchingStrategy{
    public:
    ~MatchingStrategy(){};
    virtual User * findMatch(User * user, vector<User*> &waitingUser) = 0;

};