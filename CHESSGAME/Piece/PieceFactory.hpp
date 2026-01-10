#pragma once
#include "KingPiece.hpp"
#include "Piece.hpp"
#include "QueenPiece.hpp"
#include "KnightPiece.hpp"
#include "PawnPiece.hpp"
#include "BishopPiece.hpp"
#include "RookPiece.hpp"
class Board;
class PieceFactory{
    public:
    static Piece * createPiece(PieceType pt, Color c){
        switch (pt)
        {
        case PieceType::KING: return new King(c);
        case PieceType::QUEEN: return new Queen(c);
        case PieceType::ROOK: return new Rook(c);
        case PieceType::BISHOP: return new Bishop(c);
        case PieceType::PAWN: return new Pawn(c);
        case PieceType::KNIGHT: return new Knight(c);
        default:
            break;
        }
        return nullptr;
    }
};



