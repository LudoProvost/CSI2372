#include "headers/Table.h"
using namespace std;

/**
 * @brief constructor for Table class
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

//TODO: this function
/**
 * @brief save constructor for Table class
 */
Table::Table(istream& in, const CardFactory* cf) {

}

/**
 * @brief destructor for Table class
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
 * @brief returns true when a player has won. the name of the winning player is returned by reference
 * @param playerName
 * @return bool
 * 
 */
bool Table::win(string& playerName) {
    // check if game is over
    if (deck->size() > 0) {
        return false;
    }

    // game is over, find winner
    int player1Coins = player1->getNumCoins();
    int player2Coins = player2->getNumCoins();

    // edge case, both players have same amount of coins
    if (player1Coins == player2Coins) {
        playerName = "EQUAL";
    }

    playerName = ( player1Coins > player2Coins ? player1->getName() : player2->getName() );

    return true;
}

/**
 * @brief print top card or all cards of player's hand
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
 * @brief getter for Deck
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
 * @brief insertion operator to display table
 * @param out
 * @param t
 * @return ostream&
 * 
 */
ostream& operator<<(ostream& out, Table& t) {
    out << "Player 1:\n" << *(t.player1);
    out << "Player 2:\n" << *(t.player2);
    // out << "Deck:\n" << *(t.deck);
    out << "Discard pile:\n" << *(t.discardPile);
    out << "Trading area:\n" << *(t.tradeArea);
    return out;
}

/**
 * @brief returns which player's turn it is. true for player1, false for player2
 * @return bool
 * 
 */
bool Table::getTurn() {
    return isPlayer1Turn;
}

/**
 * @brief changes who's turn it is
 * 
 */
void Table::changeTurn() {
    isPlayer1Turn = !isPlayer1Turn;
}