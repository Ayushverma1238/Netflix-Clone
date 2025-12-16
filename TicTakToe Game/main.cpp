#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include "tictaktoegame/game.hpp"
#include "Observer/observer.hpp"
#include "Players/player.hpp"
#include "Factory/gameType.hpp"
#include "Factory/tictactoefactory.hpp"
#include "Observer/consoleNotify.hpp"

using namespace std;

int main() {
    cout << "==== Tic Tac Toe Game ====\n";

    int boardSize;
    cout << "Enter the board size (e.g., 3 for 3x3): ";
    cin >> boardSize;
    cin.ignore(); // Ignore newline after cin

    // For standard TicTacToe, number of players is 2
    int numPlayers = 2;

    // Create game with board size
    unique_ptr<TicTakToeGame> game(TicTacToeFactory::createGame(GameType::STANDARD, boardSize));

    // Add observer
    unique_ptr<IObserver> notifier(new ConsoleNotifier());
    game->addObserver(notifier.get());

    // Create players dynamically
    vector<unique_ptr<Player>> players;
    for (int i = 0; i < numPlayers; ++i) {
        string name;
        char symbol;
        cout << "Enter the name of player " << (i + 1) << ": ";
        getline(cin, name);
        cout << "Enter your mark (e.g., X or O): ";
        cin >> symbol;
        cin.ignore(); // Ignore newline
        players.emplace_back(new Player(i + 1, name, new Symbol(symbol)));
        game->addPlayer(players.back().get());
    }

    // Game loop
    char choice;
    bool exitGame = false;
    while (!exitGame) {
        cout << "\nEnter (P) to Play, (E) to Exit: ";
        cin >> choice;
        cin.ignore(); // Ignore newline

        switch (toupper(choice)) {
            case 'P':
                game->play();
                // Display scores after the game
                cout << "\nFinal Scores:\n";
                for (const auto& player : players) {
                    cout << player->getName() << ": " << player->getScore() << " points\n";
                }
                break;
            case 'E':
                exitGame = true;
                cout << "Exiting game.\n";
                break;
            default:
                cout << "Invalid choice. Please enter P or E.\n";
                break;
        }
    }

    // Memory is managed by unique_ptr
    return 0;
}

