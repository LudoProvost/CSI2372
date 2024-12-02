#include "headers/Main.h"
using namespace std;

/**
 * @brief sets the names of players passed by reference
 * @param player1name
 * @param player2name
 * 
 */
void getPlayerNames(string& player1Name, string& player2Name) {
    cout << "\nEnter player 1's name: ";
    cin >> player1Name;
    cout << "Enter player 2's name: ";
    cin >> player2Name;
    cout << endl;
}

// TODO: FINISH DEBUGGING AND GET IT ACTUALLY WORKING

// the current version does not support loading saved files.
int main() {
    // initial setup:
    string player1Name, player2Name;

    getPlayerNames(player1Name, player2Name);

    Player* p1 = new Player(player1Name);
    Player* p2 = new Player(player2Name);
    DiscardPile* dp = new DiscardPile;
    TradeArea* ta = new TradeArea;
    CardFactory* cf = CardFactory::getFactory();
    Deck d = cf->getDeck();
    Table* table = new Table(p1, p2, &d, dp, ta, cf);

    // draw 5 cards for each player
    for (int i = 0; i < 5; i++) {
        p1->drawCard(d.draw());
        p2->drawCard(d.draw());
    }

    // game loop
    string winner;
    Player* currentp;
    while (!table->win(winner)) {
        // set current player and manage turns
        if (table->getTurn()) {
            currentp = p1;
        } else {
            currentp = p2;
        }
        cout << "------------- Player " << currentp->getName() << " is playing -----------\n\n";


        // display Table
        cout << *table;

        // player draws top card from Deck
        currentp->drawCard(d.draw());

        cout << currentp->getName() << "'s hand: ";
        currentp->printHand(cout, true);

        // ask player if they want to trade
        cout << "\nDo you want to trade cards from the trade area? (y/n)";
        string response;
        cin >> response;

        // if player wants to trade, try to find the card they want to trade for and throw an error otherwise
        if (response == "y") {
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

            cout << "Playing top card...\n";
            int canPlay = currentp->play();

            cout << currentp->getName() << "'s hand: ";
            currentp->printHand(cout, true);

            cout << *currentp; // print player to see chains

            if (!canPlay) {
                cout << "Couldn't play top card.\n";
                break;
            }

            // ask player if they want to repeat step 2
            cout << "Do you want to play your top card again? (y/n)";
            string response;
            cin >> response;
            if (response == "y") {
                playTurnAgain = true;
            } else {
                playTurnAgain = false;
            }
        } while (playTurnAgain);

        // step 4, discard arbitrary card from hand
        if (currentp->handEmpty()) {
            cout << "Your hand is empty, you have no cards to discard.";
        } else {

            // ask player if they want to repeat discard a card from their hand
            cout << "Do you want to discard a card from your hand? (y/n)";
            cin >> response;

            if (response == "y") {
                int idx;
                currentp->printHand(cout, true); // show hand

                while (true){ // check to make sure the user provides an int that is valid 
                    cout << "Enter the index of the card you want to discard: ";
                    cin >> idx;

                    // check if the user provides a valid number to avoid an infinite loop
                    if (cin.fail()) { 
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                        cout << "Invalid input. Please enter a valid number.\n";
                    }else if (idx < 0 || idx >= currentp->getNumCardsInHand()){
                        cout << "Invalid number. out of range.\n";
                    }else {
                        break; // a valid number in range was provided
                    }
                }
            
                Card* c = currentp->discardCard(idx); // get card and remove from hand
                cout << currentp->getName() << " discarded: " << *c << endl;
                *dp += c; // place card on discard pile
            }
        }

        // step 5, draw 3 cards from the deck and place them in the trade area
        cout << "Drawing three cards to the Trade area\n";
        for(int i = 0; i < 3; i++){
            if(!d.empty()){
                // draw a card and add it to the trade area
                Card* tradeCard=d.draw(); 
                *ta += tradeCard;
                cout << "Added Card to trade area: " << *tradeCard << "\n";
            }else {
                cout << "Deck is empty. Cannot draw more cards\n";
            }
        }

        //step 6, player will draw the card from the discard pile as long as it matches a card in the trade area
        while (!dp->empty()){
            Card* topDiscard = dp->top();
            bool matches = false;

            // check if topDiscard matches any card in the trade area
            for (Card* card: ta->getCardList()) {
                if (topDiscard->getName() == card->getName()){
                    matches = true;
                    break;
                }
            }

            if (matches){ // if it matches, the player will pick up the card
                Card* c = dp->pickUp(); 
                *ta += c;
                cout << "Moved card from Discard Pile to Trade Area: " << *c << "\n";
            }else {
                break; // exit loop if the top card does not match
            }
        }

        // step 7, iterate through the trade area and decide to chain or leave cards
        if (ta->numCards() > 0) { // make sure trade area is not empty
            cout << "Iterating through trade area to chain or leave cards\n";

            // Get a copy of the TradeArea's cards to iterate
            list<Card*> tradeCards = ta->getCardList();

            for (Card* c : tradeCards) {
                cout << "Do you want to chain card " << *c << "? (y/n): ";
                string response;
                cin >> response;

                if (response == "y") {
                    try {
                        bool chained = currentp->addCardToChain(c); // chain the card

                        if (!chained) {
                            throw runtime_error("noAvailableChain");
                        }

                        cout << "Chained card: " << *c << "\n";
                        ta->trade(c->getName()); // Remove the card from the trade area
                    } catch (const exception& e) {
                        cout << "Cannot chain card: " << *c << ". Leaving it in Trade Area.\n";
                        // *dp += c;
                        // ta->trade(c->getName());
                    }
                } else {
                    // do nothing and leave the card in trade area for next player
                    cout << "Leaving card in Trade Area: " << *c << "\n";
                }


                cout << *currentp; // print player to see chains

            }
        }

        //step 8, draw two more cards and add them to the players hand 
        cout << "Drawing two additional card to your hand\n";
        for (int i=0; i < 2; i++){
            if(!d.empty()){
                Card* additionalCard = d.draw();
                currentp->drawCard(additionalCard);
                cout << "Added card to hand: " << *additionalCard << "\n";
            }else{
                cout << "Deck is empty, no more cards can be drawn.\n";
                break;
            }
        }

        // ask player if they want to buy a third chain
        if (currentp->getNumCoins() >= 3 && !currentp->getBoughtThirdChain()) {
            cout << "Do you want to buy a third chain? (y/n): ";
                string response;
                cin >> response;

                if (response == "y") {
                    currentp->buyThirdChain();
                }
        }

        cout << "------------- End of " << currentp->getName() << "'s turn -----------\n\n";
        table->changeTurn();
    
    }

    // TODO: Reach an end stage to see if valid
    if(winner == "EQUAL"){
            cout << "The game ended in a tie. \n";
        }else {
            cout << "The winner is: " << winner << endl;
        }

    // delete all variables to clear from the memory
    delete table;
    delete ta;
    delete dp;
    delete p1;
    delete p2;

    return 0;
}
