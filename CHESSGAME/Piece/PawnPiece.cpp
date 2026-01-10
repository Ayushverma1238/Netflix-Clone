#include "PawnPiece.hpp"
#include "../Board/board.hpp"
#include "../Moves/Position.hpp"

std::vector<Position> Pawn::getPossibleMoves(Position currentPos, Board* board) const {
    std::vector<Position> moves;

    // ✅ CORRECT for your board
    int dir = (color == Color::WHITE) ? -1 : 1;

    Position OneStep(currentPos.getRow() + dir, currentPos.getCol());
    if (OneStep.isValidMove() && !board->isOccupied(OneStep)) {
        moves.push_back(OneStep);

        if (!hasMoved) {
            Position twoMoves(currentPos.getRow() + 2 * dir, currentPos.getCol());
            if (twoMoves.isValidMove() && !board->isOccupied(twoMoves)) {
                moves.push_back(twoMoves);
            }
        }
    }

    Position leftCapture(currentPos.getRow() + dir, currentPos.getCol() - 1);
    if (leftCapture.isValidMove() &&
        board->isOccupied(leftCapture) &&
        !board->isOccupiedWithSameColor(leftCapture, this->color)) {
        moves.push_back(leftCapture);
    }

    Position rightCapture(currentPos.getRow() + dir, currentPos.getCol() + 1);
    if (rightCapture.isValidMove() &&
        board->isOccupied(rightCapture) &&
        !board->isOccupiedWithSameColor(rightCapture, this->color)) {
        moves.push_back(rightCapture);
    }

    return moves;
}

