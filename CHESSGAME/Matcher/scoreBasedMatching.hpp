#pragma once
#include "matchStrategy.hpp"

class ScoreBasedMatching: public MatchingStrategy{
    int scoreTolerance;
    public:
    ScoreBasedMatching(int tol){
        scoreTolerance = tol;
    }
    User * findMatch(User * user, vector<User * > & waitingUser) override{
        User * bestMatch = nullptr;
        int bestMatchDDiff = INT_MAX;
        for(auto u : waitingUser){
            if(user->getId() != u->getId()){
                int scoreDiff = abs(user->getScore() - u->getScore());
                if(scoreDiff <= scoreTolerance && scoreDiff <bestMatchDDiff){
                    bestMatch = u;
                    bestMatchDDiff = scoreDiff;
                }
            }
        }
        return bestMatch;
    }
};