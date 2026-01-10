#pragma once
#include "Manager/GameManager.hpp"

class ChessGameDemo{
    public:
    static void demonstrateScholarMate(){
        cout << "\n==== Scholar's Meta Demo (4-move checkmate) ====" << endl;
        User * ayush = new User("DEMO_1", "Ayush");
        User * anurag = new User("DEMO_2","Anurag");

        Match * demoMatch = new Match("DEMO_MATCH", ayush, anurag);
        demoMatch->getBoard()->display();
        cout << "\nMove 1: White e2-e4" << endl;
        demoMatch->makeMove(Position('e',2), Position('e',4), ayush);

        cout << "\nMove 1: Black e7-e5" << endl;
        demoMatch->makeMove(Position('e',7), Position('e',5), anurag);

        cout << "\nMove 2: White Bf1-c4 (targeting f7)" << endl;
        demoMatch->makeMove(Position('f',1), Position('c',4), ayush);
        cout << "\nMove 2: Black Nb8-c6 (developing)" << endl;
        demoMatch->makeMove(Position('b',8), Position('c',6), anurag);

        // demoMatch->makeMove(Position(0,1), Position(2,2), anurag);

        cout << "\nMove 3: White Qd1-h5 (attacking f7 and h7)" << endl;
        demoMatch->makeMove(Position('d',1), Position('h',5), ayush);

        cout << "\nMove 3: Black Ng8-f6?? (defending h7 but exposing f7)"<<endl;
        demoMatch->makeMove(Position('g',8), Position('f',6), anurag);

        // demoMatch->makeMove(Position(0, 6), Position(2, 5), anurag);

        cout << "Move 4: White Qh5xf7# (Checkmate!)" << endl;
        bool gameEnded = demoMatch->makeMove(Position('h',5), Position('f',7), ayush);

        if(demoMatch->getStatus() != GameStatus::COMPLETED){
            cout << "Note: Checkmate detection may need refinement for this position." << endl;
        }

        cout << "\n===== Testing Chat Functionality ======" << endl;
        ayush->send(new Message(ayush->getId(), "Good game!"));
        anurag->send(new Message(anurag->getId(), "Thanks, that was a quick one!."));

        delete demoMatch;
        delete ayush;
        delete anurag;

        
    }
};