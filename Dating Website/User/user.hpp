#pragma once

#include<iostream>
#include<algorithm>
#include "preferences.hpp"
#include "userProfile.hpp"
#include "../enum/swipeAction.hpp"
#include "../NotificationServices/NotificationStrategy.hpp"
#include "../NotificationServices/UserNotificationObserver.hpp"
class User{
    string id;
    UserProfile * profile;  
    Preferences * preference;
    map<string, SwipeAction>swipHistory;
    NotificationObserver * notificationObserver;

    public:
    User(const string & userId){
        id = userId;
        profile = new UserProfile();
        preference = new Preferences();
        notificationObserver = new UserNotificationStrategy(id);
        NotificationStrategy::getInstance()->registerObserver(id, notificationObserver);

    }

    ~User(){
        delete profile;
        delete notificationObserver;
        delete preference;
        NotificationStrategy::getInstance()->removeObserver(id);
    }

    string getId() const{
        return id;
    }

    UserProfile* getProfile() const{
        return profile;

    }

    Preferences * getPreference() const{
        return preference;
    }

    void swipe(const string & userId, SwipeAction action){
        swipHistory[userId] = action;
    }

    bool hasLike(const string & userId) const{
        auto it = swipHistory.find(userId);

        if(it != swipHistory.end()){
            return it->second == SwipeAction::RIGHT;
        }
        return false;
    }

    bool hasDisLike(const string & userId) const{
        auto it = swipHistory.find(userId);
        if(it != swipHistory.end()){
            return it->second == SwipeAction::LEFT;
        }
        return false;
    }

    bool hasIntrestedWith(const string & userId)const{
        return swipHistory.find(userId) != swipHistory.end();
    }

    void displayProfile() const{
        profile->display();
    }
};