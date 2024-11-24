#include "headers/Deck.h"
using namespace std;

/**
 * @brief returns and removes top card from the deck
 * @return Card*
 * 
 */
Card* Deck::draw() {
    Card* c = this->back();

    // remove card from deck
    this->pop_back();

    return c;
}

//TODO: this function
// istream constructor
Deck::Deck(istream& in, const CardFactory* cf) {
    
}

/**
 * @brief copy-constructor for Deck class
 * @param d
 * 
 */
Deck::Deck(const Deck& d) {
    // clear this, TODO: may cause mem leak
    this->clear();

    // copy cards from d to this
    for (int i = 0; i < d.size(); i++) {
        this->push_back(new Card(*(d.at(i))));
    }
}

/**
 * @brief destructor for Deck class
 * 
 */
Deck::~Deck() {
    //TODO: i dont think this gets rid of all cards. make sure it works

    // delete all cards in deck using iterator
    vector<Card*>::iterator it;
    for (it = this->begin(); it != this->end(); it++) {
        delete *it;
    }
}

/**
 * @brief = operator for Deck class
 * @param d
 * @return Deck&
 */
Deck& Deck::operator=(const Deck& d) {
    if (this == &d) {
        return *this;
    }
    
    // clear this, TODO: may cause mem leak
    this->clear();

    // copy cards from d to this
    for (int i = 0; i < d.size(); i++) {
        this->push_back(new Card(*(d.at(i))));
    }

    return *this;
}

/**
 * @brief insertion operator to display deck
 * @param out
 * @param d
 * @return ostream&
 * 
 */
ostream& operator<<(ostream& out, Deck& d) {

    vector<Card*>::iterator it;
    for (it = d.begin(); it != d.end(); it++) {
        out << **it << " "; //TODO: not sure if this works. alternative: out << it->getName()[0] << endl;
    }
    return out;
}