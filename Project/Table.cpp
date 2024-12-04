#include "headers/Table.h"
using namespace std;

/**
 * @brief Constructor for the Table class.
 * @param p1
 * @param p2
 * @param d
 * @param dp
 * @param ta
 * @param cf
 * 
 */
Table::Table(Player* p1, Player* p2, Deck* d, DiscardPile* dp, TradeArea* ta, CardFactory* cf) {
    player1 = p1;
    player2 = p2;
    deck = d;
    discardPile = dp;
    tradeArea = ta;
    cardFactory = cf;
    isPlayer1Turn = true;
}


/**
 * @brief Istream constructor for the Table class.
 */
Table::Table(istream& in, const CardFactory* cf) {}

/**
 * @brief Destructor for the Table class.
 * 
 */
Table::~Table() {
    delete player1;
    delete player2;
    delete deck;
    delete discardPile;
    delete tradeArea;
}

/**
 * @brief Returns true when a player has won. The name of the winning player is returned by reference.
 * @param playerName
 * @return bool
 * 
 */
bool Table::win(string& playerName) {

    // Check if the deck is empty which indicates the game is over.
    if (deck->size() > 0) {
        return false;
    }

    // The game is over, find the winner through whoever has the most coins.
    int player1Coins = player1->getNumCoins();
    int player2Coins = player2->getNumCoins();

    // Edge case, both players have same amount of coins.
    if (player1Coins == player2Coins) {
        playerName = "EQUAL";
        return true;
    }

    playerName = ( player1Coins > player2Coins ? player1->getName() : player2->getName() );
    return true;
}

/**
 * @brief Print either only the top card or all the cards from the player's hand.
 * @param allPlayers
 * 
 */
void Table::printHand(bool allPlayers) {
    if (isPlayer1Turn) {
        player1->printHand(cout, allPlayers); // print hand of player 1
    } else {
        player2->printHand(cout, allPlayers); // print hand of player 2
    }
}

/**
 * @brief Getter method to retrieve the deck.
 * @return Deck
 * 
 */
Deck Table::getDeck() {
    if (deck == nullptr) {
        *deck = cardFactory->getDeck();
    }
    return *deck;
}

/**
 * @brief Insertion operator to display table to the output stream.
 * @param out
 * @param t
 * @return ostream&
 * 
 */
ostream& operator<<(ostream& out, Table& t) {
    out << "Player 1:\n" << *(t.player1);
    out << "\n";
    out << "Player 2:\n" << *(t.player2);
    out << "\n";
    out << "Discard pile: " << *(t.discardPile) << endl;
    out << "Trading area: " << *(t.tradeArea) << endl;
    return out;
}

/**
 * @brief Returns which player's turn it is. True for player1, false for player2.
 * @return bool
 * 
 */
bool Table::getTurn() {
    return isPlayer1Turn;
}

/**
 * @brief Changes who's turn it currently is.
 * 
 */
void Table::changeTurn() {
    isPlayer1Turn = !isPlayer1Turn;
}