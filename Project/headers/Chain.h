#ifndef CHAIN_H
#define CHAIN_H
#include <iostream>
#include <vector>
using namespace std;

#include "Card.h"
#include "CardFactory.h"

class Chain_Base {
    protected:
        vector<Card*> chain;
        string type;
    public:
        virtual ~Chain_Base() {}
        virtual int getNumCard() const;
        virtual string getChainType() const;
        Chain_Base& operator+=(Card* c);
        virtual int sell() const = 0;

        bool chainEmpty() const {
            return chain.empty();
        }
        
        friend ostream& operator<<(ostream& out, const Chain_Base& chain);
};

template <typename T>
class Chain : public Chain_Base{
    public:
        Chain() {
            chain = vector<Card*>();

            T card; // create card item of type T to get string name of T
            type = card.getName(); // set type to name of card
        }

        Chain(istream& in, const CardFactory* cf);

        int sell() const;
};

#endif 
