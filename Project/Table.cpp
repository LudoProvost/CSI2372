#include "headers/Table.h"
using namespace std;

Table::Table(Player* p1, Player* p2, Deck* d, DiscardPile* dp, TradeArea* ta, CardFactory* cf) {
    player1 = p1;
    player2 = p2;
    deck = d;
    discardPile = dp;
    tradeArea = ta;
    cardFactory = cf;
}

//TODO: this function
Table::Table(istream& in, const CardFactory* cf) {

}

Table::~Table() {
    delete player1;
    delete player2;
    delete deck;
    delete discardPile;
    delete tradeArea;
}

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
        playerName = "EQUAL.";
    }

    playerName = ( player1Coins > player2Coins ? player1->getName() : player2->getName() );

    return true;
}

void Table::printHand(bool allPlayers) {
    if (isPlayer1Turn) {
        player1->printHand(cout, allPlayers);
    } else {
        player2->printHand(cout, allPlayers);
    }
}

Deck Table::getDeck() {
    if (deck == nullptr) {
        deck = cf->getDeck();
    }
    return *deck;
}

ostream& Table::operator<<(ostream& out, Table& t) {
    out << "Player 1:\n" << *(t.player1);
    out << "Player 2:\n" << *(t.player2);
    // out << "Deck:\n" << *(t.deck);
    out << "Discard pile:\n" << *(t.discardPile);
    out << "Trading area:\n" << *(t.tradeArea);
    return out;
}