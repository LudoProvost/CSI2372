#include "headers/Main.h"
using namespace std;

void getPlayerNames(string& player1Name, string& player2Name) {
    cout << "\nenter player 1's name: ";
    cin >> player1Name;
    cout << "enter player 2's name: ";
    cin >> player2Name;
    cout << endl;
}

// the current version does not support loading saved files.
int main() {
    // initial setup:
    string player1Name, player2Name;

    getPlayerNames(player1Name, player2Name);

    Player* p1 = new Player(player1Name);
    Player* p2 = new Player(player2Name);
    Deck* d = new Deck;
    DiscardPile* dp = new DiscardPile;
    TradeArea* ta = new TradeArea;
    CardFactory* cf = CardFactory::getFactory();
    Table* table = new Table(p1, p2, d, dp, ta, cf);

    // draw 5 cards for each player
    for (int i = 0; i < 5; i++) {
        
    }
}