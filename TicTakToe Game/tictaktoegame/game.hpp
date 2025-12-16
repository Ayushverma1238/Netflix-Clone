#pragma once
#include "../Board/board.hpp"
#include "../Players/player.hpp"
#include "../Rules/rule.hpp"
#include "../Observer/observer.hpp"
#include<deque>
#include "../Rules/standardRule.hpp"
using namespace std;

class TicTakToeGame{
    Board * grid;
    deque<Player*> players;
    IRule * rule;
    vector<IObserver*> observers;
    bool gameOver;
    public:
    TicTakToeGame(int boardSize){
        grid = new Board(boardSize);
        rule = new StandardRule();
        gameOver = false;
    }

    void addPlayer(Player * p){
        players.push_back(p);
    }

    void addObserver(IObserver * ob){
        observers.push_back(ob);
    }

    void notifyObserver(string msg){
        for(int i = 0; i < observers.size(); i++){
            observers[i]->update(msg);
        }
    }

    void play(){
        if(players.size() < 2){
            cout << "At least 2 players needed\n";
            return;
        }
        notifyObserver("Tic Tac Toe Game Started\n");
        while(!gameOver){
            grid->display();
            Player * currPlayer = players.front();
            cout << currPlayer->getName() << " (" << currPlayer->getSymbol()->getMark() << ")- Enter row and column: "<<endl;
            int i, j;
            cin >> i >> j;
            if(rule->isValidMove(grid, i, j)){
                grid->placeMark(i, j, currPlayer->getSymbol());
                notifyObserver(currPlayer->getName() + " played (" + to_string(i) +", " + to_string(j) + ")"); 

                if(rule->checkWin(grid, currPlayer->getSymbol())){
                    grid->display();
                    cout << currPlayer->getName() << " wins!"<<endl;
                    currPlayer->incrementScore();
                    notifyObserver(currPlayer->getName() + " wins!");
                    gameOver = true;
                }else if(rule->checkDraw(grid)){
                    grid->display();
                    cout << "Match Draw!"<<endl;
                    notifyObserver("Match Draw!");
                    gameOver = true;
                }
                else{
                    players.pop_front();
                    players.push_back(currPlayer);
                }
            }else{
                cout << "Invalid Move, Try again."<<endl;
            }
        }
        
    }
    ~TicTakToeGame(){
        delete grid;
        delete rule;
    }
};