#include "headers/Deck.h"
using namespace std;

/**
 * @brief Returns and removes the top card from the deck.
 * @return Card*
 * 
 */
Card* Deck::draw() {
    Card* c = this->back();

    // Remove the card from deck and return it.
    this->pop_back();
    return c;
}

/**
 * @brief Istream constructor for the Deck class.
 */
Deck::Deck(istream& in, const CardFactory* cf) {}

/**
 * @brief Destructor for Deck class.
 * 
 */
Deck::~Deck() {
    // Delete all the cards in the deck using an iterator.
    vector<Card*>::iterator it;
    for (it = this->begin(); it != this->end(); it++) {
        delete *it;
    }
}

/**
 * @brief Insertion operator to display the deck.
 * @param out
 * @param d
 * @return ostream&
 * 
 */
ostream& operator<<(ostream& out, Deck& d) {

    // Use an iterator to go through the deck and output to the console.
    vector<Card*>::iterator it;
    for (it = d.begin(); it != d.end(); it++) {
        out << **it << " "; 
    }
    return out;
}