#pragma once
#include "NotificationObserver.hpp"
class UserNotificationStrategy: public NotificationObserver{
    string userId;

    public:
    UserNotificationStrategy(string userId){
        this->userId = userId;
    }

    void update(const string & msg) override{
        cout << "Notifiction for user " << userId << " : " << msg << endl;
    }
};