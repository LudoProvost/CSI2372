#ifndef DECK_H
#define DECK_H
#include <vector>
#include <iostream>
#include <cstdlib>
#include <sstream>
using namespace std;

#include "Card.h"
class CardFactory;

class Deck: public vector<Card*> {
    public:
        Deck() : vector<Card*>() {}; // Constructor
        Deck(istream& in, const CardFactory* cf);  // Istream Constructor
        ~Deck(); // Destructor
        
        Card* draw();
                
        friend ostream& operator<<(ostream& out, Deck& d);
};

#endif