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
        virtual int getNumCard() const;
        virtual string getChainType() const;
};

template <typename T>
class Chain : public virtual Chain_Base{
    public:
        Chain();
        Chain(istream& in, const CardFactory* cf);

        int sell();

        Chain<T>& operator+=(Card* c);

        friend ostream& operator<<(ostream& out, const Chain<Card*>& chain);
};

#endif 
