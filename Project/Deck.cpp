#include "headers/Deck.h"
using namespace std;

Card* Deck::draw() {
    Card* c = this.back();

    // remove card from deck
    this.pop_back();
    
    return c;
}

//TODO: this function
// istream constructor
Deck::Deck(istream& in, const CardFactory* cf) {
    
}

// copy-constructor
Deck::Deck(const Deck& d) {
    // clear this
    this.clear();

    // copy cards from d to this
    for (int i = 0; i < d.size(); i++) {
        this.push_back(d.at(i));
    }
}

// destructor
//TODO: i dont think this gets rid of all cards. make sure it works
Deck::~Deck() {
    // delete all cards in deck
    for (int i = 0; i < this.size(); i++) {
        delete this.at(i);
    }
}

// assignment operator
Deck& Deck::operator=(const Deck& d) {
    if (this == &d) {
        return *this;
    }
    
    // clear this
    this.clear();

    // copy cards from d to this
    for (int i = 0; i < d.size(); i++) {
        this.push_back(d.at(i));
    }

    return *this;
}
