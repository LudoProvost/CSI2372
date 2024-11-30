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
    string winner;
    while (!table->win(winner)) {
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

        //TODO: only for debugging, remove before submission
        cout << *currentp;

        // ask player if they want to trade
        cout << "Do you want to trade cards from the trade area? (yes/no)";
        string response;
        cin >> response;

        // if player wants to trade, try to find the card they want to trade for and throw an error otherwise
        if (response == "yes") {
            // chain all possible cards in tradearea, discard the rest
            for (Card* c : ta->getCardList()) {
                bool toDiscard = true;
                // try all chains of current player
                for (int i = 0; i < currentp->getNumChains(); i++) {

                    // check if card matches a chain
                    if (c->getName() == currentp->operator[](i).getChainType()) {
                        currentp->operator[](i) += c; // add card to matching chain
                        toDiscard = false;
                        break;
                    }
                }

                // if c is not added to a chain, add it to discard pile 
                if (toDiscard) {
                    *dp += c;
                }
            }
        } else {
            // discard all cards in the trade area
            for (Card* c: ta->getCardList()) {
                *dp += c;
            }
        }

        // step 2, play topmost card from Hand, can be repeated
        bool playTurnAgain = false;
        do {
            
            //TODO: only for debugging, remove before submission
            cout << *currentp;

            currentp->play();

            // ask player if they want to repeat step 2
            cout << "Do you want to play your top card again? (yes/no)";
            string response;
            cin >> response;

            if (response == "yes") {
                playTurnAgain = true;
            } else {
                playTurnAgain = false;
            }

        } while (playTurnAgain);

        // step 4, discard arbitrary card from hand
        

    }
}