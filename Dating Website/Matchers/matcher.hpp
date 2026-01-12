#pragma once

#include<iostream>
#include "../User/user.hpp"
#include<string>
#include "../enum/matcherType.hpp"

using namespace std;

class Matcher{
    public:
    virtual ~Matcher() {};
    virtual double calculateMatchScore(User * user1, User * user2) =0;
};