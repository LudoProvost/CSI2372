#include "headers/Deck.h"
using namespace std;

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

// copy-constructor
Deck::Deck(const Deck& d) {
    // clear this, TODO: may cause mem leak
    this->clear();

    // copy cards from d to this
    for (int i = 0; i < d.size(); i++) {
        this->push_back(new Card(*(d.at(i))));
    }
}

// destructor
//TODO: i dont think this gets rid of all cards. make sure it works
Deck::~Deck() {
    // delete all cards in deck using iterator
    vector<Card*>::iterator it;
    for (it = this->begin(); it != this->end(); it++) {
        delete *it;
    }
}

// assignment operator
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

ostream& operator<<(ostream& out, Deck& d) {

    vector<Card*>::iterator it;
    for (it = d.begin(); it != d.end(); it++) {
        out << *it << " "; //TODO: not sure if this works. alternative: out << it->getName()[0] << endl;
    }
    return out;
}