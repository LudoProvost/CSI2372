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

    //init chain vector
    for (int i = 0; i < 2 + boughtThirdChain; i++) {
        Chain_Base* temp = nullptr;
        chains.push_back(temp);
    }
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

/**
 * @brief chains the player's top-most card. also attempts to sell all chains
 * 
 */
void Player::play() {
    
    //edge case, empty hand
    if (hand->getCardDeque().empty()) {
        return;
    }

    int emptyChainIdx = -1;
    Card* topCard = hand->top();

    // find and add top card to existing chain
    for (int i = 0; i < 2 + boughtThirdChain; i++) {

        auto& chain = chains[i];

        // update emptyChainFound if chain is empty
        if (chain == nullptr) {
            emptyChainIdx = i;
            continue; // go to next chain
        }

        // condition to find compatible chain
        if (topCard->getName() == chain->getChainType()) {
            chain->operator+=(hand->play()); // remove top card from hand using play() and add it to chain
        }
    }

    // condition to check if all chains are used
    if (emptyChainIdx == -1) {
        // no chain matching top card found and max number of chains reached
        // attempt to sell a chain 
        emptyChainIdx = tradeChain(); // will be set to the index of the chain sold (ready to be replaced) or -1 if no tradable chain
    }
    
    // no chain found, create new chain at empty chain
    if (emptyChainIdx != -1) {
        auto* newChain = createChain(topCard);
        newChain->operator+=(hand->play()); // add top card to chain
        chains[emptyChainIdx] = newChain; // add new chain to chains
    } else {
        cout << "could not play top card.";
    }
}

/**
 * @brief creates a chain of the same type as the card passed
 * @param c
 * @return Chain_Base*
 * 
 */
Chain_Base* Player::createChain(Card* c) {
    Chain_Base* chain = nullptr;
    string cType = c->getName();

    if (cType == "Blue") {
        chain = new Chain<Blue>();
    } else if (cType == "Chili") {
        chain = new Chain<Chili>();
    } else if (cType == "Stink") {
        chain = new Chain<Stink>();   
    } else if (cType == "Green") {
        chain = new Chain<Green>(); 
    } else if (cType == "soy") {
        chain = new Chain<soy>(); 
    } else if (cType == "black") {
        chain = new Chain<black>(); 
    } else if (cType == "Red") {
        chain = new Chain<Red>(); 
    } else if (cType == "garden") {
        chain = new Chain<garden>(); 
    }
    
    return chain;
}

/**
 * @brief attempts to sell a chain. returns -1 if no chain could be sold, else it returns the index of the sold chain in chains
 * @return int
 * TODO: not sure if this should attempt to trade all chains or just the first tradable one. right not it is only trading the first one 
 */
int Player::tradeChain() {
    
    // iterate through chains
    for (int i = 0; i < 2 + boughtThirdChain; i++) {

        int valueOfCurrentChain = chains[i]->sell();

        // finds a chain that is able to be sold
        if (valueOfCurrentChain != 0) {
            *this += valueOfCurrentChain; // add coins to player
            chains[i] = nullptr; // delete chain
            return i; // return index of the now empty chain
        }
    }

    // return -1 if no chains were tradable
    return -1;
}
