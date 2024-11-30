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
 * @brief returns number of cards in the chain
 * @return int
 * 
 */
int Chain_Base::getNumCard() const {
    return chain.size();
}

/**
 * @brief returns the type of the chain
 * @return string
 * 
 */
string Chain_Base::getChainType() const {
    return type;
}

//TODO: this function
template <typename T>
Chain<T>::Chain(istream& in, const CardFactory* cf) {

}

/**
 * @brief counts number of cards in current chain and returns number of coins its worth
 * @return int
 * 
 */
template <typename T>
int Chain<T>::sell() const {
    T cardType;
    int numCard = getNumCard();

    // find value of chain
    for (int coinNum = 4; coinNum >= 1; coinNum--) {
        int cardsPerCoin = cardType.getCardsPerCoin(coinNum);

        // edge case for invalid value of chains, just ignore the iteration
        if (cardsPerCoin == -1) {
            continue;
        }
        
        if (numCard >= cardsPerCoin) {
            return coinNum;
        }
    }

    // if coinNum wasn't returned in the for loop, the player doesn't have enough cards to get coins.
    return 0;
}

/**
 * @brief adds the card passed to the function to the chain
 * @param c
 * @return Chain_Base&
 * 
 */
Chain_Base& Chain_Base::operator+=(Card* c) {
    
    //TODO: may need an edge case to set type of chain to type of c if chain is empty

    // throw type exception if type of c does not match T
    //TODO: idk if this needs a return
    if (c->getName() != getChainType()) {
        throw runtime_error("IllegalType");
    }

    chain.push_back(c);
    return *this;
}

/**
 * @brief insertion operator to display chain
 * @param out
 * @param chain
 * @return ostream&
 * 
 */
ostream& operator<<(ostream& out, const Chain_Base& chain) {

    // edge case, chain empty
    if (chain.chain.empty()) { //TODO: FIX, THIS CRASHES FOR SOME REASON
        cout << "empty chain";
    } else {
        // print full name and tab
        cout << chain.getChainType() << "\t";

        // print number of cards
        int numCard = chain.getNumCard();
        for (int i = 0; i < numCard; i++) {
            cout << chain.getChainType()[0] << " ";
        }
    }
    return out;
}