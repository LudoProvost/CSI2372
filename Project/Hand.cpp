#include "headers/Hand.h"
using namespace std;


//TODO: this function
Hand::Hand(istream& in, const CardFactory* cf) {

}

Card* Hand::play() {
    Card* c = cardDeque.front(); // save ref of top card

    cardDeque.pop_front(); // remove top card

    return c;
}

Card* Hand::top() {
    return cardDeque.front(); // return top card of deque
}

Hand& Hand::operator+=(Card* c) {
    cardDeque.push_back(c); // add card c
    return *this;
}

Card* Hand::operator[](int i) {
    Card* c = cardDeque[i]; // save ref of card at index i

    cardDeque.erase(cardDeque.begin()+i); // remove card at index i

    return c;
}

ostream& operator<<(ostream& out, const Hand& h) {
    
    // not sure if auto works here, but "deque<Card*>::iterator it;" wasn't working
    for (auto it = h.cardDeque.begin(); it != h.cardDeque.end(); it++) {
        out << *it << " "; //TODO: not sure if this works. alternative: out << it->getName()[0] << endl;
    }
    return out;
}