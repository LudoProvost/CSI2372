#include "headers/Chain.h"
using namespace std;

template class Chain<Blue>;
template class Chain<Chili>;
template class Chain<Stink>;
template class Chain<Green>;
template class Chain<soy>;
template class Chain<black>;
template class Chain<Red>;
template class Chain<garden>;

/**
 * @brief Returns the number of cards in the chain.
 * @return int
 * 
 */
int Chain_Base::getNumCard() const {
    return chain.size();
}

/**
 * @brief Returns the type of the chain.
 * @return string
 * 
 */
string Chain_Base::getChainType() const {
    return type;
}

/**
 * @brief Istream constructor for the Chain class.
 */
template <typename T>
Chain<T>::Chain(istream& in, const CardFactory* cf) {}

/**
 * @brief Counts the number of cards in the current chain and returns the number of coins it is worth.
 * @return int
 * 
 */
template <typename T>
int Chain<T>::sell() const {
    T cardType;
    int numCard = getNumCard();

    // Find the value of the chain in coins.
    for (int coinNum = 4; coinNum >= 1; coinNum--) {
        int cardsPerCoin = cardType.getCardsPerCoin(coinNum);

        // Edge case for an invalid value of chains. Ignore the iteration and continue.
        if (cardsPerCoin == -1) {
            continue;
        }
        
        // If the chain is valid to sell, return the numer of coins it is worth.
        if (numCard >= cardsPerCoin) {
            return coinNum;
        }
    }

    // If coinNum wasn't returned in the for loop, the player did not have enough cards to recieve coins.
    return 0;
}

/**
 * @brief Adds the card passed to the function onto the chain.
 * @param c
 * @return Chain_Base&
 * 
 */
Chain_Base& Chain_Base::operator+=(Card* c) {
    
    // Set the type of the chain to type 'c' if the chain is empty.
    if(chain.empty()){
        type = c->getName();
    }

    // Throw type exception if type of argument 'c' does not match type of the chain.
    if (c->getName() != getChainType()) {
        throw runtime_error("IllegalType");
    }

    chain.push_back(c);
    return *this;
}

/**
 * @brief Insertion operator to display the chain.
 * @param out
 * @param chain
 * @return ostream&
 * 
 */
ostream& operator<<(ostream& out, const Chain_Base& chain) {

    // Edge case, the chain is empty.
    if (chain.chain.empty()) { 
        cout << "empty chain";
    } else {
        // Print full name and tab character.
        cout << chain.getChainType() << "\t";

        // Print the first letter of the card for the number of cards in the chain.
        int numCard = chain.getNumCard();
        for (int i = 0; i < numCard; i++) {
            cout << chain.getChainType()[0] << " ";
        }
    }
    return out;
}