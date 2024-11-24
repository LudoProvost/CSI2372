#include "headers/DiscardPile.h"
using namespace std;

//TODO: this function
DiscardPile::DiscardPile(istream& in, const CardFactory* cf) {

}

/**
 * @brief returns and removes top card from discard pile
 * @return Card*
 * 
 */
Card* DiscardPile::pickUp() {
    Card* c = this->back();

    // remove card from deck
    this->pop_back();
    
    return c;
}

/**
 * @brief returns but doesn't remove top card from discard pile
 * @return Card*
 * 
 */
Card* DiscardPile::top() {
    return this->back();
}

/**
 * @brief inserts all cards in discard pile in the stream
 * @param out
 * 
 */
void DiscardPile::print(ostream& out) {
    vector<Card*>::iterator it;
    for (it = this->begin(); it != this->end(); it++) {
        out << **it; //TODO: not sure if this works. alternative: out << it->getName()[0] << endl;
    }
}

/**
 * @brief adds card c to the discardpile
 * @param c
 * @return DiscardPile&
 * 
 */
DiscardPile& DiscardPile::operator+=(Card* c) {
    this->push_back(c);
    return *this;
}

/**
 * @brief insertion operator to display discard pile
 * @param out
 * @param dp
 * @return ostream&
 * 
 */
ostream& operator<<(ostream& out, DiscardPile& dp) {
    // edge case, dp empty
    if (dp.size() == 0) {
        return out;
    }
    
    out << *(dp.back());
    return out;
}