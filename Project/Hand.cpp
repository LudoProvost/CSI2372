
#include "headers/Hand.h"
using namespace std;

/**
 * @brief Save constructor for Hand class
 */
Hand::Hand(istream& in, const CardFactory* cf) {
    string CardType;

    // Enter the stream, then create a new card matching the name of the card provided
    while (in >> CardType){ 

        Card* newCard = cf->createCard(CardType); // could also declare newCard as a nullptr earlier on
        cardDeque.push_back(newCard); // add the new card to the players hand
    }
}

/**
 * @brief returns and removes top card from player's hand
 * @return Card*
 * 
 */
Card* Hand::play() {
    Card* c = cardDeque.front(); // save ref of top card

    cardDeque.pop_front(); // remove top card

    return c;
}

/**
 * @brief returns but doesn't remove top card from player's hand
 * @return Card*
 * 
 */
Card* Hand::top() {
    return cardDeque.front(); // return top card of deque
}

/**
 * @brief adds card c to rear of hand
 * @param c
 * @return Hand&
 * 
 */
Hand& Hand::operator+=(Card* c) {
    cardDeque.push_back(c); // add card c
    return *this;
}

/**
 * @brief returns and removes card at the given index i
 * @param i
 * @return Card*
 * 
 */
Card* Hand::operator[](int i) {
    Card* c = cardDeque[i]; // save ref of card at index i

    cardDeque.erase(cardDeque.begin()+i); // remove card at index i

    return c;
}

/**
 * @brief getter for cardDeque
 * @return const deque<Card*>&
 */
const deque<Card*>& Hand::getCardDeque() const {
    return cardDeque;
}

/**
 * @brief insertion operator to display hand
 * @param out
 * @param h
 * @return ostream&
 */
ostream& operator<<(ostream& out, const Hand& h) {
    for (const auto& card : h.getCardDeque()) { 
        // TODO: is this an alternative to the method below?
        card -> print(out); // loop over each card stored in cardDeque and use Card's built-in print method
        out << " ";
    }
    out << endl;
    return out;

    /*
    * // not sure if auto works here, but "deque<Card*>::iterator it;" wasn't working
    * for (auto it = h.cardDeque.begin(); it != h.cardDeque.end(); it++) {
    *     out << **it << " "; //TODO: not sure if this works. alternative: out << it->getName()[0] << endl;
    * }
    * return out;
    */

}

/**
 * @brief returns number of cards in hand
 * @return int
 */
int Hand::numberOfCardsInHand() {
    return cardDeque.size();
}