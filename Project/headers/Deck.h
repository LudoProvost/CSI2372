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
        Deck(istream&, const CardFactory*);  // istream constructor
        Deck(const Deck&); // copy-constructor
        ~Deck(); // destructor
        
        Deck& operator=(const Deck&); // assignment operator
        
        friend ostream& operator<<(ostream& out, Deck& d) {
            
            for (int i = 0; i < this.size(); i++) {
                out << *d.at(i); //TODO: not sure if this works. alternative: out << d.at(i)->getName()[0] << endl;
            }
            return out;
        }
}