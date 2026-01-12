#pragma once

#include "locationStrategy.hpp"
#include "basicLocationStrategy.hpp"

class LocationService{
    LocationStrategy * strategy;
    static LocationService * instance;
    LocationService(){
        strategy = new BasicLocationStrategy();
    }
    public:
    static LocationService* getInstance(){
        if(!instance){
            instance = new LocationService();
        }
        return instance;
    }

    ~LocationService(){
        delete strategy;
    }

    void setStrategy(LocationStrategy*strategy) {
        delete strategy;
        this->strategy = strategy;
    }

    vector<User*> findNearbyUser(const Location & location, double maxDis, const vector<User*>& allUsers){
        return strategy->findNearByUser(location, maxDis, allUsers);
    }
};

LocationService * LocationService :: instance = nullptr;