#include "headers/Hand.h"
using namespace std;


//TODO: this function
Hand::Hand(istream& in, const CardFactory* cf) {

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
 * @brief insertion operator to display hand
 * @param out
 * @param h
 * @return ostream&
 */
ostream& operator<<(ostream& out, const Hand& h) {
    
    // not sure if auto works here, but "deque<Card*>::iterator it;" wasn't working
    for (auto it = h.cardDeque.begin(); it != h.cardDeque.end(); it++) {
        out << **it << " "; //TODO: not sure if this works. alternative: out << it->getName()[0] << endl;
    }
    return out;
}