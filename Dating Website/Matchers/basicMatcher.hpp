#pragma once
#include "matcher.hpp"
#include "../User/user.hpp"
using namespace std;

class BasicMatcher : public Matcher{
    public:

    double calculateMatchScore(User *  user1, User * user2) override{
        bool user1LikesUser2Gender = user1->getPreference()->isIntrestedInGender(user2->getProfile()->getGender());
        bool user2LikesUser1Gender = user2->getPreference()->isIntrestedInGender(user1->getProfile()->getGender());

        if(!user1LikesUser2Gender || !user2LikesUser1Gender){
            return 0.0;
        }

        double distance = user1->getProfile()->getLocation().distanceInKm(user2->getProfile()->getLocation());
        bool user1LikesUser2Distance = user1->getPreference()->isDistanceAcceptable(distance);
        bool user2LikesUser1Distance = user2->getPreference()->isDistanceAcceptable(distance);
        if(!user1LikesUser2Distance || !user2LikesUser1Distance){
            return 0.0;
        }
        return 0.5;
    }
};