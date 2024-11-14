#ifndef DECK_H
#define DECK_H
#include <vector>
#include <iostream>
#include <cstdlib>
#include <sstream>
using namespace std;

#include "Card.h"
#include "CardFactory.h"

class Deck: public vector<Card*> {
    public:
        Deck() : vector<Card*>() {}; // constructor
        Deck(istream& in, const CardFactory* cf);  // istream constructor
        Deck(const Deck& d); // copy-constructor TODO: needed?
        ~Deck(); // destructor
        
        Card* draw();

        Deck& operator=(const Deck& d); // assignment operator TODO: needed?
        
        friend ostream& operator<<(ostream& out, Deck& d);
};

#endif