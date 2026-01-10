#include "RookPiece.hpp"
#include "../Board/board.hpp"
#include "../Moves/Position.hpp"

std::vector<Position> Rook::getPossibleMoves(Position currentPos, Board * board)const{
        std::vector<Position> moves;
        int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        for(int d = 0; d< 4; d++){
            for(int i = 1; i < 8; i++){
                Position newPos(currentPos.getRow() + dir[d][0] * i , currentPos.getCol() + dir[d][1] * i);
                if(!newPos.isValidMove()) break;
                if(board->isOccupiedWithSameColor(newPos, this->color)) break;
                moves.push_back(newPos);
                if(board->isOccupied(newPos)) break;
            }
        }
        return moves;
    }