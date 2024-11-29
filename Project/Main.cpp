#include "headers/Main.h"
using namespace std;

/**
 * @brief sets the names of players passed by reference
 * @param player1name
 * @param player2name
 * 
 */
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

    // shuffle deck
    *d = cf->getDeck();

    // draw 5 cards for each player
    for (int i = 0; i < 5; i++) {
        p1->drawCard(d->draw());
        p2->drawCard(d->draw());
    }

    // game loop
    while (d->size() != 0) {
        // set current player and manage turns
        Player* currentp;
        if (table->getTurn()) {
            currentp = p1;
        } else {
            currentp = p2;
        }
        table->changeTurn(); // change turn, next game loop iteration will be player2's turn

        // display Table
        cout << *table;

        // player draws top card from Deck
        currentp->drawCard(d->draw());

        // ask player if they want to trade
        cout << "Do you want to trade a card from the trade area? (y/n)";
        string response;
        cin >> response;

        // TODO: review the logic below
        // TODO: add way to chain or discard cards from the tradea area
        // if player wants to trade, try to find the card they want to trade for and throw an error otherwise
        if (response == "yes") {
            cout << "Enter the name of the card you want to trade: ";
            string cardName;
            cin >> cardName;

            try { 
                
                Card* tradedCard = ta->trade(cardName);  
                currentp->drawCard(tradedCard);  // add the traded card to the player's hand
                cout << "You traded for " << cardName << endl;
            } catch (const invalid_argument& a) {
                cout << a.what() << endl; // catch invalid arguments
            }
        }


        //TODO: once tradearea is implemented. can the player selectively decide which card to chain and discard?


        
    }
}