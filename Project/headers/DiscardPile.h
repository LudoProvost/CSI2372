#ifndef DISCARDPILE_H
#define DISCARDPILE_H
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;

#include "CardFactory.h"
#include "Card.h"

class DiscardPile: public vector<Card*> {
    public:
        DiscardPile() : vector<Card*>() {}; // Constructor
        DiscardPile(istream& in, const CardFactory* cf); // Istream Constructor

        Card* pickUp();
        Card* top();
        void print(ostream& out);

        DiscardPile& operator+=(Card* c);
        friend ostream& operator<<(ostream& out, DiscardPile& dp);
};

#endif