#include "headers/Player.h"
using namespace std;

/**
 * @brief Constructor for the Player class.
 * @param n
 * 
 */
Player::Player(string& n) {
    name = n;
    coins = 0;
    hand = new Hand;
    boughtThirdChain = false;
}

/**
 * @brief Istream constructor for the Player class.
 */
Player::Player(istream& in, const CardFactory* cf) {}


/**
 * @brief Returns the name of the player.
 * @return string
 * 
 */
string Player::getName() const {
    return name;
}

/**
 * @brief Returns the number of coins the player has.
 * @return int
 * 
 */
int Player::getNumCoins() const {
    return coins;
}

/**
 * @brief Returns the maximum number of chains the player is allowed to have.
 * @return int
 * 
 */
int Player::getMaxNumChains() const {

    // Checks if the player has bought a third chain. Return 3 if so, and 2 otherwise.
    return (boughtThirdChain) ? 3 : 2;
}

/**
 * @brief Returns the current number of chains the player has.
 * @return int
 * 
 */
int Player::getNumChains() const {
    return chains.size();
}

/**
 * @brief Allows user to purchase an empty third chain. An exception is thrown if the player does not have enough coins to do so.
 * 
 */
void Player::buyThirdChain() {
    
    // Edge case, player does not have enough coins to purchase a third chain.
    if (coins < 3) {
        throw runtime_error("NotEnoughCoins");
    }

    boughtThirdChain = true; 
    coins -= 3; 
}

/**
 * @brief Prints either only the top card or all the card's from the player's hand depending on the value of 'allCards'.
 * @param out
 * @param allCards
 * 
 */
void Player::printHand(ostream& out, bool allCards) {
    if (allCards) {
        out << *(hand); // Print all cards of the player's hand.
    } else {
        out << *(hand->top()); // Print only the top card of player's hand.
    }
}

/**
 * @brief Returns the chain at position i.
 * @param i
 * @return Chain_Base&
 * 
 */
Chain_Base& Player::operator[](int i) const {
    return *(chains.at(i)); 
}

/**
 * @brief Adds a number of coins 'n' to the player's coin count.
 * @param n
 * @return Player&
 * 
 */
Player& Player::operator+=(int n) {

    coins += n; // add n coins
    return *this;
}

/**
 * @brief Insertion operator to display player, their coin count and all their chains.
 * @param out
 * @param p
 * @return ostream&
 * 
 */
ostream& operator<<(ostream& out, const Player& p) {
    
    // Print the player's name and their number of coins.
    out << p.name << "\t" << p.coins << " coins\n";

    // Print all of the player's current chains.
    for (int i = 0; i < p.getNumChains(); i++) {
        out << p.operator[](i) << endl;
    }
    return out;
}

/**
 * @brief Adds card c to the player's hand.
 * @param c
 * 
 */
void Player::drawCard(Card* c) {
    *hand += c; // Add card c to player's hand.
}

/**
 * @brief Chains the player's top-most card. Also attempts to sell all chains. Returns false if player cant play any more cards.
 * @return bool
 */
bool Player::play() {
    
    //Edge case, the player's hand is empty.
    if (hand->getCardDeque().empty()) {
        return false;
    }

    Card* topCard = hand->top();

    // find and add the top card to an existing chain.
    for (int i = 0; i < getNumChains(); i++) {

        auto& chain = chains[i];

        // Condition to find a compatible chain to add the card to.
        if (topCard->getName() == chain->getChainType()) {

            // Removes the top card from the player's hand using play() and adds it to the chain.
            chain->operator+=(hand->play()); 
            return true;
        }
    }

    // If no chain matching the top card is found and the max number of chains allowed for the player is reached. Attempt to sell one of the player's chains.
    if (chains.size() == getMaxNumChains()) {
        
        // Will be set to the index of the chain that was sold (ready to be replaced by the new chain) or -1 if no chain was tradeable.
        int idx = tradeChain(); 

        // If a chain was sold, create a new chain at that index with the player's top card.
        if (idx != -1) { 
            auto* newChain = createChain(topCard);

            // Add the top card to the chain .
            newChain->operator+=(hand->play());
            chains.push_back(newChain);
            return true;
        }
    }

    // If no existing matching chain was found, and the player does not have the max number of chains. Create a new chain for the player.
    if (chains.size() < getMaxNumChains()) {
        auto* newChain = createChain(topCard);

        // Add the player's top card to the chain.
        newChain->operator+=(hand->play());

        // Add this chain to the list of chains.
        chains.push_back(newChain); 
    } else {
        return false;
    }

    return true;
}

/**
 * @brief Creates a new chain of the same type as the card c passed through.
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
 * @brief Sells a chain for the highest amount of coins and then adds coins to the player.
 * @return int
 * 
 */
int Player::tradeChain() {
    
    // Iterate through the player's chains.
    int highestCostIdx = 0;
    int highestCost = chains[highestCostIdx]->sell();

    for (int i = 0; i < getNumChains(); i++) {

        int valueOfCurrentChain = chains[i]->sell();

        // Finds a chain that is able to be sold.
        if (valueOfCurrentChain > highestCost) {
            highestCost = valueOfCurrentChain;
            highestCostIdx = i;
        } else if (valueOfCurrentChain == highestCost) {

            // If both chains found are worth the same number of coins, sell the one with the least amount of cards.
            if (chains[i]->getNumCard() < chains[highestCostIdx]->getNumCard()) {
                highestCost = valueOfCurrentChain;
                highestCostIdx = i;
            }
        }
    }

    // Print the chain that was sold and for how much.
    cout << "Sold the following chain for " << highestCost << " coins: ";
    cout << *chains[highestCostIdx] << "\n";

    *this += highestCost; // add coins to player
    delete chains[highestCostIdx]; // delete chain
    chains.erase(chains.begin() + highestCostIdx); // delete chain from vector
    return highestCostIdx; // return index of the now empty chain
}

/**
 * @brief Attempts to add card c to one of the players existing chain, creates a new chain or sells one otherwise.
 * @param c
 * @return bool
 */
bool Player::addCardToChain(Card* c) {


    // Attempt to add card c to an existing compatible chain.
    for (int i = 0; i < getNumChains(); i++) {
        auto& chain = chains[i];

        // Add the card to the chain if an existing chain was found.
        if (c->getName() == chain->getChainType()) { 
            *chain += c; 
            return true; 
        }
    }

    // If no compatible chain exists, attempt to create a new one.
    if (chains.size() < getMaxNumChains()) {

        // Create a new chain matching the type of the card.
        Chain_Base* newChain = createChain(c); 

        if (newChain) {
            *newChain += c; // add card to the new chain
            chains.push_back(newChain);
            return true;
        } 
    } else {

        // If the maximum number of chains was reached, attempt to sell an existing chain.
        // Will be set to the index of the chain that was sold (ready to be replaced by the new chain) or -1 if no chain was tradeable.
        int idx = tradeChain(); 

        // If a chain was sold, create a new chain at that index with the new card.
        if (idx != -1) { 
            Chain_Base* newChain = createChain(c);

            if (newChain) {
                *newChain += c;
                chains.push_back(newChain);
                return true;
            } 
        } 
    }
    return false;
}

/**
 * @brief Returns the number of card currently in the players hand.
 */
int Player::getNumCardsInHand() const{
    return hand->numberOfCardsInHand();
}

/**
 * @brief Returns and discards the card at index i.
 * @param i
 * @return Card*
 */
Card* Player::discardCard(int i) {
    return (*hand)[i];
}

/**
 * @brief Returns true if hand is empty.
 * @return bool
 */
bool Player::handEmpty() {
    return (hand->numberOfCardsInHand() == 0);
}

/**
 * @brief Getter method for boughtThirdChain.
 * @return bool
 * 
 */
bool Player::getBoughtThirdChain() {
    return boughtThirdChain;
}