#include "headers/Player.h"
using namespace std;

Player::Player(string& n) {
    name = n;
    coins = 0;
    //TODO: init vector of chains
    boughtThirdChain = false;
}

//TODO: this function
Player::Player(istream& in, const CardFactory* cf) {

}
        
string Player::getName() {
    return name;
}

int Player::getNumCoins() {
    return coins;
}

int Player::getMaxNumChains() {
    return (boughtThirdChain) ? 3 : 2;
}

//TODO: this function once chains is implemented
int Player::getNumChains() {

}

//TODO: this function once chains is implemented
void Player::buyThirdChain() {

}

void Player::printHand(ostream& out, bool allCards) {
    if (allCards) {
        out << *(hand);
    } else {
        out << *(hand->top());
    }
}

Chain& Player::operator[](int i) {
    //TODO: once chain is implemented
}

Player& Player::operator+=(int n) {
    coins += n;
    return *this;
}

ostream& operator<<(ostream& out, const Player& p) {
    out << p.name << "\t\t" << p.coins << " coins\n";

    // print all of the player's chains
    for (int i = 0; i < 2 + p.boughtThirdChain; i++) {
        out << ;//TODO: once Chain is implemented
    }

}

void Player::drawCard(Card* c) {
    *hand += c;
}