#include "KnightPiece.hpp"
#include "../Board/board.hpp"
#include "../Moves/Position.hpp"

std::vector<Position> Knight::getPossibleMoves(Position currentPos, Board* board) const {
    std::vector<Position> moves;

    static const int dir[8][2] = {
        {-2, -1}, {-2,  1},
        {-1, -2}, {-1,  2},
        { 1, -2}, { 1,  2},
        { 2, -1}, { 2,  1}
    };

    for (int d = 0; d < 8; d++) {
        Position newPos(
            currentPos.getRow() + dir[d][0],
            currentPos.getCol() + dir[d][1]
        );

        if (!newPos.isValidMove())
            continue;

        if (board->isOccupiedWithSameColor(newPos, color))
            continue;

        moves.push_back(newPos);
    }

    return moves;
}
