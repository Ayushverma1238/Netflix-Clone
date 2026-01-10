#include "KingPiece.hpp"
#include "../Board/board.hpp"
#include "../Moves/Position.hpp"

std::vector<Position>
King::getPossibleMoves(Position currentPos, Board* board) const {
    std::vector<Position> moves;
    if (!board) return moves;

    static const int directions[8][2] = {
        {-1,-1},{-1,0},{-1,1},
        {0,-1},        {0,1},
        {1,-1},{1,0},{1,1}
    };

    for (const auto& d : directions) {
        Position newPos(
            currentPos.getRow() + d[0],
            currentPos.getCol() + d[1]
        );

        if (!newPos.isValidMove()) continue;

        if (!board->isOccupiedWithSameColor(newPos, color))
            moves.push_back(newPos);
    }
    return moves;
}
