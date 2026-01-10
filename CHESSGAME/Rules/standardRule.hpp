#pragma once
#include "ChessRule.hpp"

class StandardChessRule : public ChessRule {
public:

    bool isValidMove(Move m, Board* b) override {
        Piece* p = m.getPiece();
        if (p == nullptr) return false;

        vector<Position> possibleMove = p->getPossibleMoves(m.getFrom(), b);
        bool validDes = false;

        for (const Position& pos : possibleMove) {
            if (pos == m.getTo()) {
                validDes = true;
                break;
            }
        }

        if (!validDes) return false;

        // ✅ FIX 1: must NOT cause check
        return !wouldCauseCheck(m, b, p->getColor());
    }

    bool wouldCauseCheck(Move m, Board* b, Color c) override {
        Piece* movingPiece = b->getPiece(m.getFrom());
        Piece* capturePiece = b->getPiece(m.getTo());

        if (movingPiece == nullptr) return true;

        // simulate move
        b->removePiece(m.getFrom());
        if (capturePiece != nullptr) {
            b->removePiece(m.getTo());
        }
        b->placePiece(m.getTo(), movingPiece);

        bool isCheck = isInCheck(c, b);

        // ✅ FIX 2: rollback board state
        b->removePiece(m.getTo());
        b->placePiece(m.getFrom(), movingPiece);
        if (capturePiece != nullptr) {
            b->placePiece(m.getTo(), capturePiece);
        }

        return isCheck;
    }
    bool isInCheck(Color c, Board * b) override{
        Position kingPos = b->findKing(c);
        if(kingPos.getRow() == -1) return false;

        Color opponentColor = (c == Color::WHITE) ? Color::BLACK : Color ::WHITE;
        vector<Position> opponentPos = b->getAllPiecePosition(opponentColor);
        for(const Position & pos : opponentPos){
            Piece * piece = b->getPiece(pos);
            vector<Position> moves = piece->getPossibleMoves(pos, b);
            for(const auto m : moves){
                if(m == kingPos){
                    return true;
                }
            }
        }
        return false;
    }

    bool isCheckMate(Color c, Board * b) override{
        if(!isInCheck(c, b)) return false;
        vector<Position>piecePos = b->getAllPiecePosition(c);

        for(const Position& pos : piecePos){
            Piece * piece = b->getPiece(pos);
            vector<Position> moves = piece->getPossibleMoves(pos, b);
            for(const auto m : moves){
                Move move(pos, m, piece, b->getPiece(m));
                if(isValidMove(move, b)){
                    return false;
                }
            }
            
        }
        return true;
    }

    bool isStaleMate(Color c, Board * b) override{
        if(isInCheck(c, b)) return false;
        vector<Position> piecePos = b->getAllPiecePosition(c);
        for(const Position & pos: piecePos){
            Piece * piece = b->getPiece(pos);
            vector<Position> moves = piece->getPossibleMoves(pos, b);
            for(const Position & m : moves){
                Move move(pos, m, piece, b->getPiece(m));
                if(isValidMove(move, b)){
                    return false;
                }
            }
        }
        return true;
    }
    
};