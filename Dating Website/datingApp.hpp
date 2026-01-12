#pragma once
#include "User/user.hpp"
#include "ChatRoom/chatRoom.hpp"
#include "Matchers/matcher.hpp"
#include "Matchers/matcherFactory.hpp"
#include<algorithm>
#include "NotificationServices/NotificationStrategy.hpp"
#include "LocationStrategys/locationServices.hpp"
class DatingApp{
    vector<User*> users;
    vector<ChatRoom*> chatRooms;
    Matcher * matcher;
    static DatingApp * instance;
    DatingApp(){
        matcher = MatcherFactory :: createMatcher(MathcherType::LOCATION_BASED);
    }
    public:
    static DatingApp * getInstance(){
        if(!instance){
            instance = new DatingApp();
        }
        return instance;
    }
    ~DatingApp(){
        for(auto user : users){
            delete user;
        }

        for(auto chatroom : chatRooms){
            delete chatroom;
        }

        delete matcher;
    }

    void setMatcher(MathcherType type){
        delete matcher;
        matcher = MatcherFactory::createMatcher(type);
    }

    User * createUser(const string & userId){
        for(auto user : users){
            if(user->getId()== userId){
                return user;
            }
        }
        User * user = new User(userId);
        users.push_back(user);
        return user;
    }

    User * getUser(const string & userId){
        for(auto user : users){
            if(user->getId() == userId){
                return user;
            }
        }
        return nullptr;
    }

    User * getUserById(const string & userId) const{
        for(auto user : users){
            if(user->getId() == userId){
                return user;
            }
        }
        return nullptr;
    }

    vector<User*> findNearByUsers(const string & userId, double maxDis) const{
        User * user = getUserById(userId);
        if(user == nullptr){
            return vector<User*> ();
        }

        vector<User*> nearbyUser  = LocationService::getInstance()->findNearbyUser(
            user->getProfile()->getLocation(), maxDis, users
        );

        nearbyUser.erase(remove(nearbyUser.begin(), nearbyUser.end(), user) , nearbyUser.end());

        vector<User*> filteredUsers;
        for(auto otherUser: nearbyUser){
            if(user->hasIntrestedWith(otherUser->getId()))
            continue;

            double score = matcher->calculateMatchScore(user, otherUser);

            if(score > 0){
                filteredUsers.push_back(otherUser);
            }
        }
        return filteredUsers;
    }

    bool swipe(const string & userId, const string& targetUserId, SwipeAction action){
        User * user = getUserById(userId);
        User * targetUser = getUserById(targetUserId);
        if(user == nullptr || targetUser == nullptr){
            cout << "User not found." << endl;
            return false;
        }
        user->swipe(targetUserId, action);

        if(action == SwipeAction::RIGHT && targetUser->hasLike(userId)){
            string chatRoomId = userId + "_" + targetUserId;
            ChatRoom * chatRoom = new ChatRoom(chatRoomId, userId, targetUserId);
            chatRooms.push_back(chatRoom);

            NotificationStrategy::getInstance()->notifyUser(userId, "You have a new match with "+ targetUser->getProfile()->getName() + "!");
            NotificationStrategy::getInstance()->notifyUser(targetUserId, "You have a new match with "+ user->getProfile()->getName() + "!");
            return true;
        }
        return false;
    }

    ChatRoom * getChatRoom(const string & user1Id, const string & user2Id){
        for(auto chatRoom : chatRooms){
            if(chatRoom->hasParticipent(user1Id) && chatRoom->hasParticipent(user2Id)){
                return chatRoom;
            }
        }
        return nullptr;
    }

    void sendMessage(const string & senderId, const string& receiverId ,const string & content){
        ChatRoom * chatRoom = getChatRoom(senderId, receiverId);
        if(chatRoom == nullptr){
            return;
        }
        chatRoom->addMessages(senderId, content);
        NotificationStrategy::getInstance()->notifyUser(receiverId, "New Message from " + getUserById(senderId)->getProfile()->getName());

    }

    void displayUser(const string & userId){
        User * user = getUserById(userId);
        if(user == nullptr){
            cout <<"User not found."<< endl;
            return;
        }
        user->displayProfile();
    }

    void displayChatRoom(const string & user1Id, const string& user2Id){ 
        ChatRoom * chatRoom = getChatRoom(user1Id, user2Id);
        if(chatRoom == nullptr){
            cout << "No Chat Room found between these users."<<endl;
            return;
        }
        chatRoom->displayChat();
    }

};

DatingApp *DatingApp :: instance = NULL;