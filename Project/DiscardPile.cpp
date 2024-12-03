#include "headers/DiscardPile.h"
using namespace std;

/**
 * @brief Istream constructor for the DiscardPile class.
 */
DiscardPile::DiscardPile(istream& in, const CardFactory* cf) {}

/**
 * @brief Returns and removes the top card from the discard pile.
 * @return Card*
 * 
 */
Card* DiscardPile::pickUp() {
    Card* c = this->back();

    // Remove card from deck and return it.
    this->pop_back();
    return c;
}

/**
 * @brief Returns but does not remove the top card from the discard pile.
 * @return Card*
 * 
 */
Card* DiscardPile::top() {
    return this->back();
}

/**
 * @brief Adds all the cards in the discard pile to the output stream.
 * @param out
 * 
 */
void DiscardPile::print(ostream& out) {
    vector<Card*>::iterator it;
    for (it = this->begin(); it != this->end(); it++) {
        out << **it; 
    }
}

/**
 * @brief Adds the passed through card to the discard pile.
 * @param c
 * @return DiscardPile&
 * 
 */
DiscardPile& DiscardPile::operator+=(Card* c) {
    this->push_back(c);
    return *this;
}

/**
 * @brief Insertion operator to display only the top card of the discard pile.
 * @param out
 * @param dp
 * @return ostream&
 * 
 */
ostream& operator<<(ostream& out, DiscardPile& dp) {
    // Edge case, the discard pile is empty.
    if (dp.size() == 0) {
        return out;
    }
    
    out << *(dp.back());
    return out;
}