#pragma once
#include "../User/user.hpp"
#include "../Rules/ChessRule.hpp"
#include "../Rules/standardRule.hpp"
#include "../Board/board.hpp"
#include "../enum/GameStatus.hpp"
#include "../Message/chatMediator.hpp"

class Match : public ChatMediator {
    string matchId;
    User* blackUser;
    User* whiteUser;
    Board* board;
    ChessRule* rules;
    Color turn;
    GameStatus status;
    vector<Move> moveHistory;
    vector<Message*> chatHistory;

public:
    Match(string id, User* white, User* black) {
        matchId = id;
        blackUser = black;
        whiteUser = white;
        turn = Color::WHITE;
        board = new Board();
        rules = new StandardChessRule();
        status = GameStatus::IN_PROGRESS;

        whiteUser->setMediator(this);
        blackUser->setMediator(this);

        cout << "Match Started between "
             << white->getName() << " (WHITE) and "
             << black->getName() << " (BLACK)" << endl;

        board->display();
    }

    ~Match() {
        delete board;
        delete rules;
        for (auto msg : chatHistory) {
            delete msg;
        }
    }

    Color getPlayerColor(User* user) {
        if (user == whiteUser) return Color::WHITE;
        return Color::BLACK;
    }

    bool makeMove(Position from, Position to, User* player) {
        if (status != GameStatus::IN_PROGRESS) {
            cout << "Game is not in progress" << endl;
            return false;
        }

        Color playerCol = getPlayerColor(player);

        if (playerCol != turn) {
            cout << "It's not your turn!." << endl;
            return false;
        }

        Piece* piece = board->getPiece(from);
        if (piece == nullptr || piece->getColor() != playerCol) {
            cout << "Invalid Piece selection!." << endl;
            return false;
        }

        Move move(from, to, piece, board->getPiece(to));

        if (!rules->isValidMove(move, board)) {
            cout << "Invalid Move." << endl;
            return false;
        }

        board->movePiece(from, to);
        moveHistory.push_back(move);

        cout << player->getName()
             << " moved " << piece->getSymbol()
             << " from " << from.toChessNotation()
             << " to " << to.toChessNotation() << endl;

        board->display();

        Color opponentColor = (turn == Color::WHITE) ? Color::BLACK : Color::WHITE;

        if (rules->isCheckMate(opponentColor, board)) {
            endGame(player, "Checkmate");
        }
        else if (rules->isStaleMate(opponentColor, board)) {
            endGame(player, "Stalemate");
        }
        else {
            turn = opponentColor;
            if (rules->isInCheck(opponentColor, board)) {
                cout << getPlayerByColor(opponentColor)->getName()
                     << " is in check." << endl;
            }
        }

        return true;
    }

    void endGame(User* winner, string reason) {
        status = GameStatus::COMPLETED;

        if (winner != nullptr) {
            User* looser = (winner == whiteUser) ? blackUser : whiteUser;
            winner->incrementScore(30);
            looser->decrementScore(20);

            cout << "Game ended - "
                 << winner->getName()
                 << " win by " << reason << "!." << endl;

            cout << "Score updated - "
                 << winner->getName() << " +30 "
                 << looser->getName() << " -20" << endl;
        }
        else {
            cout << "Game ended in " << reason
                 << " no score is updated." << endl;
        }
    }

    User* getPlayerByColor(Color c) {
        if (c == Color::WHITE) return whiteUser;
        return blackUser;
    }

    void send(Message* msg, User* user) override {
        chatHistory.push_back(msg);
        User* recipient = (user == whiteUser) ? blackUser : whiteUser;
        recipient->receive(msg);

        cout << "Chat in match "
             << matchId << " - "
             << msg->getContent() << endl;
    }

    void quitGame(User* user) {
        User* opponent = (user == whiteUser) ? blackUser : whiteUser;
        endGame(opponent, "quit");
        user->decrementScore(50);
        cout << user->getName()
             << " quit the game. decrementing score -50." << endl;
    }

    void addUser(User* user) override {}

    void removeUser(User* user) override {
        quitGame(user);
    }

    string getMatchId() const { return matchId; }
    GameStatus getStatus() const { return status; }
    User* getWhitePlayer() const { return whiteUser; }
    User* getBlackPlayer() const { return blackUser; }
    Board* getBoard() const { return board; }
};
