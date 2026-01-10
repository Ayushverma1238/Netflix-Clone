#include <iostream>
#include "chessGameDemo.hpp"
using namespace std;

int main(){
    cout << "\n========= Chess System with Design Patterns Demo =======" << endl;
    ChessGameDemo::demonstrateScholarMate();
    cout << "\n==== Game Manager Demo =================="<< endl;
    GameManager * gm = GameManager::getInstance();
    User * avanish = new User("USER_1", "Avanish");
    User * manish = new User("USER_2", "Manish");
    User * abhishek = new User("USER_3", "Abhishek");
    User * anurag = new User("USER_4", "Anurag");

    cout << "\nUsers: " << avanish->toString() << ", " << manish->toString() << ", " << abhishek->toString() << anurag->toString() << endl;
    gm->requestMatch(avanish);
    gm->requestMatch(manish);
    gm->requestMatch(abhishek);
    gm->requestMatch(anurag);
    gm->diplayAllActiveMatch();

    // delete avanish;
    // delete manish;
    // delete abhishek;

    // delete GameManager::getInstance();
    return 0;
}