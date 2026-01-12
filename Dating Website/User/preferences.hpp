#pragma once

#include <iostream>
#include<string> 
#include<map>
#include<vector>
#include<algorithm>
#include "../enum/Gender.hpp"

using namespace std;

class Preferences{
    int minAge;
    int maxAge;
    double maxDis;
    vector<string> interest;
    vector<Gender> interestedIn;
    public:
    Preferences(){
        this->minAge = 18;
        this->maxAge = 25;
        this->maxDis = 100.0;
    }

    void addGenderPreferences(Gender  gender){
        interestedIn.push_back(gender);
    }

    void removeGenderPreferences(Gender  gender){
        interestedIn.erase(remove(interestedIn.begin(), interestedIn.end(), gender), interestedIn.end());
    }

    void setAgeRange(int min, int max){
        this->minAge = min;
        this->maxAge = max;
    }

    void setMaxDistance(double distance){
        this->maxDis = distance;
    }

    void addInterested(const string & interested){
        interest.push_back(interested);
    }
    void removeIntrested(const string & intre){
        interest.erase(remove(interest.begin(), interest.end(), intre), interest.end());
    }

    bool isIntrestedInGender(Gender gender) const{
        return find(interestedIn.begin(), interestedIn.end(), gender) != interestedIn.end();
    }

    bool isAgeInRange(int age) const{
        return (age >= minAge && age <= maxAge);
    }

    bool isDistanceAcceptable(int distance) const{
        return distance <= maxDis;
    }
    const vector<string> & getIntrested() const{
        return interest;
    }

    const vector<Gender > & getIntrestedInGender() const{
        return interestedIn;
    }

    int getMinAge() const{
        return minAge;
    }

    int getMaxAge() const{
        return maxAge;
    }

    double getMaxDistance() const{
        return maxDis;
    }
};