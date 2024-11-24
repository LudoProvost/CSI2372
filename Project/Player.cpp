#include "headers/Player.h"
using namespace std;

Player::Player(string& n) {
    name = n;
    coins = 0;
    hand = new Hand;
    boughtThirdChain = false;
}

//TODO: this function
Player::Player(istream& in, const CardFactory* cf) {

}
        
string Player::getName() const {
    return name;
}

int Player::getNumCoins() const {
    return coins;
}

int Player::getMaxNumChains() const {
    return (boughtThirdChain) ? 3 : 2;
}

int Player::getNumChains() const {
    return chains.size();
}

void Player::buyThirdChain() {
    
    // edge case, player does not have enough coins
    if (coins < 3) {
        throw runtime_error("NotEnoughCoins");
    }

    boughtThirdChain = true;
}

void Player::printHand(ostream& out, bool allCards) {
    if (allCards) {
        out << *(hand); // print all cards of the player's hand
    } else {
        out << *(hand->top()); // print top card of player's hand
    }
}

Chain_Base& Player::operator[](int i) {
    return *(chains.at(i)); // return chain at index i
}

Player& Player::operator+=(int n) {
    coins += n; // add n coins
    return *this;
}

ostream& operator<<(ostream& out, const Player& p) {
    
    // print name and number of coins
    out << p.name << "\t" << p.coins << " coins\n";

    // print all of the player's chains
    for (int i = 0; i < p.getNumChains(); i++) {
        out << p.chains.at(i) << endl;
    }
    return out;
}

void Player::drawCard(Card* c) {
    *hand += c; // add card c to player's hand
}