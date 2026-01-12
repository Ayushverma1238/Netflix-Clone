#pragma once

#include "matcher.hpp"
#include "basicMatcher.hpp"
#include <algorithm> // for std::find

class InteresetBasedMatcher : public Matcher {
public:
    double calculateMatchScore(User * user1, User * user2) override {
        BasicMatcher basicMatcher;
        double baseScore = basicMatcher.calculateMatchScore(user1, user2);

        if (baseScore == 0.0) {
            return 0.0;
        }

        std::vector<std::string> user1InterestNames;
        for (const auto & interest : user1->getProfile()->getIntrested()) {
            user1InterestNames.push_back(interest->getName());
        }

        int sharedInterest = 0;
        for (const auto & interest : user2->getProfile()->getIntrested()) {
            if (std::find(user1InterestNames.begin(), user1InterestNames.end(), interest->getName()) != user1InterestNames.end()) {
                sharedInterest++;
            }
        }

        double maxInterests = std::max(
            user1->getProfile()->getIntrested().size(),
            user2->getProfile()->getIntrested().size()
        );

        double interestScore = maxInterests > 0 ? 0.5 * (sharedInterest / maxInterests) : 0.0;

        return baseScore + interestScore;
    }
};
