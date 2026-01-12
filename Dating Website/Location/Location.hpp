#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <memory>
class Location{
    double latitude;
    double longitude;
    public:
    Location(){
        this->latitude = 0.0;
        this->longitude = 0.0; 
    }

    Location(double lat, double longitude){
        this->latitude = lat;
        this->longitude = longitude;
    }

    double getLatitude() const{
        return latitude;
    }

    double getLongitude() const{
        return longitude;
    }

    void setLatitude(double lat){
        latitude = lat;
    }

    void setLongitude(double longi){
        longitude = longi;
    }
    double distanceInKm(const Location & other) const{
        const double earthRadiusKm = 6371.0;
        double dLat =( other.latitude-latitude) * M_PI/180.0;
        double dLong =( other.longitude-longitude) * M_PI/180.0;
        double a = sin(dLat/2) * sin(dLat/2) + cos(latitude * M_PI/180.0) * cos(other.latitude * M_PI/180.0) * sin(dLong/2) * sin(dLong/2);
        double c = 2 * atan2(sqrt(a), sqrt(1-a));
        return earthRadiusKm * c;
    }

};