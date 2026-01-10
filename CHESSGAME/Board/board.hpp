#pragma once
// #include "../Piece/Piece.hpp"
// #include "../Moves/Move.hpp"
#include "../Moves/Position.hpp"
#include "../Piece/PieceFactory.hpp"
class Move;
class Piece;
// class PieceFactory;
#include <map>
class Board{
    Piece * board[8][8];
    map<Position, Piece*> piecePos;
    public:
    Board(){
        for(int i = 0; i< 8; i++){
            for(int j = 0;j < 8; j++){
                board[i][j] = nullptr;
            }
        }
        initialize();
    }

    ~Board(){
        for(int i = 0; i< 8; i++){
            for(int j =0; j < 8; j++){
                delete board[i][j];
                board[i][j] = nullptr;
            }
        }
        piecePos.clear();
    }

    void initialize(){
        placePiece(Position(7, 0), PieceFactory::createPiece(PieceType::ROOK, Color::WHITE));
        placePiece(Position(7, 1), PieceFactory::createPiece(PieceType::KNIGHT, Color::WHITE));
        placePiece(Position(7, 2), PieceFactory::createPiece(PieceType::BISHOP, Color::WHITE));
        placePiece(Position(7, 3), PieceFactory::createPiece(PieceType::QUEEN, Color::WHITE));
        placePiece(Position(7, 4), PieceFactory::createPiece(PieceType::KING, Color::WHITE));
        placePiece(Position(7, 5), PieceFactory::createPiece(PieceType::BISHOP, Color::WHITE));
        placePiece(Position(7, 6), PieceFactory::createPiece(PieceType::KNIGHT, Color::WHITE));
        placePiece(Position(7, 7), PieceFactory::createPiece(PieceType::ROOK, Color::WHITE));
        
        for (int i = 0; i < 8; i++) {
            placePiece(Position(6, i), PieceFactory::createPiece(PieceType::PAWN, Color::WHITE));
        }
        
        // Initialize black pieces
        placePiece(Position(0, 0), PieceFactory::createPiece(PieceType::ROOK, Color::BLACK));
        placePiece(Position(0, 1), PieceFactory::createPiece(PieceType::KNIGHT, Color::BLACK));
        placePiece(Position(0, 2), PieceFactory::createPiece(PieceType::BISHOP, Color::BLACK));
        placePiece(Position(0, 3), PieceFactory::createPiece(PieceType::QUEEN, Color::BLACK));
        placePiece(Position(0, 4), PieceFactory::createPiece(PieceType::KING, Color::BLACK));
        placePiece(Position(0, 5), PieceFactory::createPiece(PieceType::BISHOP, Color::BLACK));
        placePiece(Position(0, 6), PieceFactory::createPiece(PieceType::KNIGHT, Color::BLACK));
        placePiece(Position(0, 7), PieceFactory::createPiece(PieceType::ROOK, Color::BLACK));
        
        for (int i = 0; i < 8; i++) {
            placePiece(Position(1, i), PieceFactory::createPiece(PieceType::PAWN, Color::BLACK));
        }
    }

    void placePiece(Position pos, Piece* piece) {
        board[pos.getRow()][pos.getCol()] = piece;
        piecePos[pos] = piece;
    }

    void removePiece(Position pos){
        board[pos.getRow()][pos.getCol()] = nullptr;
        piecePos.erase(pos);
    }

    Piece * getPiece(Position pos){
        return board[pos.getRow()][pos.getCol()];
    }

    bool isOccupied(Position pos){
        return getPiece(pos) != nullptr;
    }

    bool isOccupiedWithSameColor(Position pos, Color c){
        Piece * p = getPiece(pos);
        if(p!= nullptr && p->getColor() == c)return true;
        return false;
    }

    void movePiece(Position from, Position to){
        Piece * piece = getPiece(from);
        if(piece != nullptr){
            Piece * capturedPiece = getPiece(to);
            if(capturedPiece != nullptr){
                delete capturedPiece;
                piecePos.erase(to);
            }

            board[from.getRow()][from.getCol()] = nullptr;
            board[to.getRow()][to.getCol()] = piece;
            piecePos.erase(from);
            piecePos[to] = piece;
            piece->setHasMoved(true);
        }
    }

    Position findKing(Color c) {
        for(auto & pair : piecePos){
            if(pair.second->getPieceType() == PieceType::KING && pair.second->getColor() == c){
                return pair.first;
            }
        }
        return Position(-1, -1);
    }

    vector<Position> getAllPiecePosition(Color c){
        vector<Position> position;
        for(auto & pair : piecePos){
            if(pair.second->getColor() == c){
                position.push_back(pair.first);
            }
        }
        return position;
    }

   void display() {
        constexpr int cellW = 3;  // cell width

        // — horizontal border —
        auto printBorder = [&]() {
            std::cout << "  +";
            for (int i = 0; i < 8; ++i)
                std::cout << std::string(cellW, '-') << "+";
            std::cout << "\n";
        };

        // — top border —
        printBorder();

        // — column labels inside the grid —
        std::cout << "  |";
        for (char f = 'a'; f <= 'h'; ++f) {
            int pad = (cellW - 1) / 2;
            std::cout
                << std::string(pad, ' ')
                << f
                << std::string(cellW - 1 - pad, ' ')
                << "|";
        }
        std::cout << "\n";

        // — border under labels —
        printBorder();

        // — each rank of pieces —
        for (int rank = 8; rank >= 1; --rank) {
            int row = 8 - rank;
            std::cout << rank << " |";

            for (int file = 0; file < 8; ++file) {
                Piece* p = board[row][file];
                std::string s = p ? p->toString() : "  ";  // two spaces if empty

                // center a 2-char string in cellW
                int pad = (cellW - 2) / 2;
                std::cout
                    << std::string(pad, ' ')
                    << s
                    << std::string(cellW - 2 - pad, ' ')
                    << "|";
            }

            std::cout << " " << rank << "\n";
            printBorder();
        }

        // — bottom labels inside the grid —
        std::cout << "  |";
        for (char f = 'a'; f <= 'h'; ++f) {
            int pad = (cellW - 1) / 2;
            std::cout
                << std::string(pad, ' ')
                << f
                << std::string(cellW - 1 - pad, ' ')
                << "|";
        }
        std::cout << "\n";

        // — final border —
        printBorder();
        cout << "----------------------------------------------------------------------\n";
    }
};  
