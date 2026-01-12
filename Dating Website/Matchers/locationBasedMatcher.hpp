#pragma once

#include "matcher.hpp"
#include "basicMatcher.hpp"
#include "interestbasedMatcher.hpp"

class LocationBasedMatcher : public Matcher{
    public:
    double calculateMatchScore(User * user1, User * user2) override{
        InteresetBasedMatcher interestsMatcher;
        double baseScore = interestsMatcher.calculateMatchScore(user1, user2);

        if(baseScore == 0.0){
            return 0.0;
        }

        double distance = user1->getProfile()->getLocation().distanceInKm(user2->getProfile()->getLocation());
        double maxDistance =  min(user1->getPreference()->getMaxDistance(), user2->getPreference()->getMaxDistance());

        double proximityScore = maxDistance > 0 ? 0.2 * (1.0- (distance/ maxDistance)) : 0.0;
        return baseScore + proximityScore;
    }
};