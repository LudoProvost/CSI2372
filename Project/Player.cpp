#include "headers/Player.h"
using namespace std;

/**
 * @brief constructor for Player class
 * @param n
 * 
 */
Player::Player(string& n) {
    name = n;
    coins = 0;
    hand = new Hand;
    boughtThirdChain = false;
}

//TODO: this function
Player::Player(istream& in, const CardFactory* cf) {

}

/**
 * @brief returns name of player
 * @return string
 * 
 */
string Player::getName() const {
    return name;
}

/**
 * @brief returns number of coins the player has
 * @return int
 * 
 */
int Player::getNumCoins() const {
    return coins;
}

/**
 * @brief returns max number of chains the player is allowed to have
 * @return int
 * 
 */
int Player::getMaxNumChains() const {
    return (boughtThirdChain) ? 3 : 2;
}

/**
 * @brief returns number of chains the player has
 * @return int
 * 
 */
int Player::getNumChains() const {
    return chains.size();
}

/**
 * @brief allows user to use a third chain. An exception is thrown if the player does not have enough coins
 * 
 */
void Player::buyThirdChain() {
    
    // edge case, player does not have enough coins
    if (coins < 3) {
        throw runtime_error("NotEnoughCoins");
    }

    boughtThirdChain = true;
}

/**
 * @brief prints top card or all cards of player's hand
 * @param out
 * @param allCards
 * 
 */
void Player::printHand(ostream& out, bool allCards) {
    if (allCards) {
        out << *(hand); // print all cards of the player's hand
    } else {
        out << *(hand->top()); // print top card of player's hand
    }
}

/**
 * @brief returns chain at position i
 * @param i
 * @return Chain_Base&
 * 
 */
Chain_Base& Player::operator[](int i) {
    return *(chains.at(i)); // return chain at index i
}

/**
 * @brief adds a number of coins to the player's coins
 * @param n
 * @return Player&
 * 
 */
Player& Player::operator+=(int n) {
    coins += n; // add n coins
    return *this;
}

/**
 * @brief insertion operator to display player
 * @param out
 * @param p
 * @return ostream&
 * 
 */
ostream& operator<<(ostream& out, const Player& p) {
    
    // print name and number of coins
    out << p.name << "\t" << p.coins << " coins\n";

    // print all of the player's chains
    for (int i = 0; i < p.getNumChains(); i++) {
        out << p.chains.at(i) << endl;
    }
    return out;
}

/**
 * @brief adds card c to the player's hand
 * @param c
 * 
 */
void Player::drawCard(Card* c) {
    *hand += c; // add card c to player's hand
}