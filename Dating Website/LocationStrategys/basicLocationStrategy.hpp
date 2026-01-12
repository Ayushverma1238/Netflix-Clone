#pragma once
#include "locationStrategy.hpp"
using namespace std;
class BasicLocationStrategy : public LocationStrategy{
    public:
    vector<User*> findNearByUser(const Location & location, double maxDis, const vector<User*>& allUsers){
        vector<User*> users;
        for(auto user : allUsers ){
            double distance = location.distanceInKm(user->getProfile()->getLocation());
            if(distance <= maxDis){
                users.push_back(user);
            }
        }
        return users;
    }
};