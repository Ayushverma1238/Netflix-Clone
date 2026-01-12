#pragma once

#include<vector>
#include "../User/user.hpp"
#include "../Location/Location.hpp"
using namespace std;

class LocationStrategy{
    public:
    virtual ~LocationStrategy(){};

    virtual vector<User*> findNearByUser(const Location & location, double maxDis, const vector<User*>& allUsers) = 0;
};