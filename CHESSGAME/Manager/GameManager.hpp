#pragma once
#include <map>
#include<string>
#include <vector>
#include<algorithm>
#include "../Matcher/matchStrategy.hpp"
#include "../Message/message.hpp"
#include "../Matcher/scoreBasedMatching.hpp"
#include "../Matcher/Match.hpp"
using namespace std;

class Board;
class Piece;
class User;

class GameManager{
    static GameManager * instance;
    map<string , Match*> activeMatch;
    vector<User * >waitingUser;
    MatchingStrategy * matchStrategy;
    int matchCount = 0;
    GameManager(){
        matchStrategy = new ScoreBasedMatching(100);
        matchCount = 0;
    }
    public:
    static GameManager * getInstance(){
        if(instance == nullptr){
            instance = new GameManager();
            
        }
        return instance;

    }

    ~GameManager(){
       
        delete matchStrategy;
        for(auto & pair : activeMatch){
            delete pair.second;
        }
    }

    void requestMatch(User * user){
        cout << user->getName() << " is looking for a match......" << endl;
        User * opponent = matchStrategy->findMatch(user, waitingUser);
        if(opponent != nullptr){
            waitingUser.erase(remove(waitingUser.begin(), waitingUser.end(), opponent), waitingUser.end());
            string matchId = "MATCH" + to_string(++matchCount);
            Match * match = new Match(matchId, user, opponent);
            activeMatch[matchId]= match;
            cout << "Match found! " << user->getName() << " vs " << opponent->getName() << endl;
            match->getBoard()->display();
        }else{
            waitingUser.push_back(user);
            cout << user->getName() << " added to waiting list."<<endl;
        }
    }

    void makeMove(string matchId, Position from, Position to, User * player){
        if(activeMatch.find(matchId) != activeMatch.end()){
            Match * match = activeMatch[matchId];
            match->makeMove(from, to, player);
            if(match->getStatus() == GameStatus::COMPLETED){
                delete match;
                activeMatch.erase(matchId);
                cout << "Match " << matchId << " completed and removed from active matches."<<endl;
            }
        }
    }

    void quitMatch(string matchId, User * player){
        if(activeMatch.find(matchId) != activeMatch.end()){
            Match * match = activeMatch[matchId];
            match->quitGame(player);
            delete match;
            activeMatch.erase(matchId);
        }
    }

    void sendChatMessage(string matchId, string msg, User * player){
        if(activeMatch.find(matchId) != activeMatch.end()){
            Match * match = activeMatch[matchId];
            Message* message = new Message(player->getId(), msg);
            match->send(message, player);

        }
    }

    Match * getUserMatch(string matchId){
        if(activeMatch.find(matchId) != activeMatch.end()){
            return activeMatch[matchId];
        }
        return nullptr;
    }

    void diplayAllActiveMatch(){
        cout << "\n====== Active Matches =========\n";
        for(auto& it : activeMatch){
            Match * match = it.second;
            cout << "Match " << match->getMatchId() << ": " << match->getWhitePlayer()->getName() << " vs " << match->getBlackPlayer()->getName() << endl;
        }
        cout << "Total active match: " << activeMatch.size() << endl;
        cout << "Users waiting: " << waitingUser.size() << endl;
    }

};

GameManager * GameManager::instance = nullptr;