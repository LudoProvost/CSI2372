#include "headers/Chain.h"
using namespace std;

int Chain_Base::getNumCard() const {
    return chain.size();
}

string Chain_Base::getChainType() const {
    return type;
}

template <typename T>
Chain<T>::Chain() {
    T card; // create card item of type T to get string name of T
    type = card.getName(); // set type to name of card
}

//TODO: this function
template <typename T>
Chain<T>::Chain(istream& in, const CardFactory* cf) {

}

template <typename T>
int Chain<T>::sell() {
    T cardType;
    int numCard = getNumCard();

    // find value of chain
    for (int coinNum = 4; coinNum >= 1; coinNum--) {
        int cardsPerCoin = cardType.getCardsPerCoin(i);

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

template <typename T>
Chain<T>& Chain<T>::operator+=(Card* c) {
    
    //TODO: may need an edge case to set type of chain to type of c if chain is empty

    // throw type exception if type of c does not match T
    //TODO: idk if this needs a return
    if (!(c->getName()).compare(getChainType())) {
        throw runtime_error("IllegalType");
    }

    chain.push_back(c);
    return *this;
}

ostream& operator<<(ostream& out, const Chain<Card*>& chain) {
    // print full name and tab
    out << chain.getChainType() << "\t";

    // print number of cards
    int numCard = chain.getNumCard();
    for (int i = 0; i < numCard; i++) {
        out << chain.getChainType()[0] << " ";
    }
    return out;
}