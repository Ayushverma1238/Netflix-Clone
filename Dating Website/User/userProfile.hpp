#pragma once

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include "preferences.hpp"
#include "../intrested/intrested.hpp"
#include "../Location/Location.hpp"

class UserProfile{
    string name;
    int age;
    Gender gender;
    string bio;
    vector<string>photos;
    vector<Intreseted * > intresets;
    Location  location;
    public:
    UserProfile(){
        name = "";
        age = 0;
        gender = Gender::OTHER;
    }

    ~UserProfile(){
        for(auto intrest : intresets){
            delete intrest;
        }
    }

    void setName(const string & name){
        this->name = name;
    }

    string getName() const{
        return name;
    }

    void setAge(int age){
        this->age = age;
    }

    int getAge() const{
        return age;
    }

    void setGender(Gender g) {
        gender = g;
    }

    Gender getGender() const{
        return gender;
    }

    void setBio(const string & b){
        bio = b;
    }

    void addPhotos(const string & imgpath){
        photos.push_back(imgpath);
    }

    void removePhoto(const string & imgPath) {
        photos.erase(remove(photos.begin(), photos.end(), imgPath) , photos.end());

    }

    void addIntreset(const string & name, const string & category){
        Intreseted * intreset = new Intreseted(name, category);
        intresets.push_back(intreset);

    }
    void removeIntreset(const string & name){
        auto it = find_if(intresets.begin(), intresets.end(), [&name](const Intreseted* interest){
            return interest->getName() == name;
        });
        if(it != intresets.end()){
            delete *it;
            intresets.erase(it);
        }
    }

    void setLocation(const Location loc){
        location = loc;
    }

    const Location& getLocation() const{
        return location;
    }

    const vector<Intreseted*>& getIntrested() const{
        return intresets;

    }

    void display()  const {
        cout <<"=========Profile==========" << endl;
        cout << "Name: " << name<<endl;
        cout << "Age: " << age<<endl;
        cout << "Gender: ";
        switch (gender)
        {
        case Gender::MALE :
            cout<<"Male";
            break;
        case Gender::FEMALE : cout<<"Female";break;
        case Gender::OTHER : cout<<"Other"; break;
        default:
            break;
        }
        cout << endl;
        cout << "Bio: " << bio<<endl;
        cout <<"Photos: ";
        for(const auto & it : photos){
            cout << it << ",";
        }
        cout << endl;
        
        cout <<"Intrested: ";
        for(const auto & it : intresets){
            cout << it->getName() << "(" << it->getCategory()<<"), ";
        }
        cout <<endl;
        cout << "Location: " << location.getLatitude() << ", " << location.getLongitude()<<endl;
        cout << "==============================="<<endl;
    }
};