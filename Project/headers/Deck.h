#include <vector>
#include <iostream>
#include <cstdlib>
#include <sstream>
using namespace std;

#include "Card.h"
#include "CardFactory.h"

class Deck: public vector<Card*> {
    public:
        Card* draw();
        
        Deck() : vector<Card*>() {}; // constructor
        Deck(istream& in, const CardFactory* cf);  // istream constructor
        Deck(const Deck& d); // copy-constructor
        ~Deck(); // destructor
        
        Deck& operator=(const Deck& d); // assignment operator
        
        friend ostream& operator<<(ostream& out, Deck& d);
}