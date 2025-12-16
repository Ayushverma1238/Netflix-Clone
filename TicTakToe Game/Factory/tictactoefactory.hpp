#pragma once
#include "gameType.hpp"
#include "../tictaktoegame/game.hpp"

class TicTacToeFactory{
    public:
    static TicTakToeGame * createGame(GameType gt, int boardSize){
        if(GameType::STANDARD == gt)
            return new TicTakToeGame(boardSize);
        return nullptr;
    }

};
