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
        Chain_Base& operator+=(Card* c);
        virtual int sell() const = 0;
};

template <typename T>
class Chain : public Chain_Base{
    public:
        Chain() {
            if (typeid(T) == typeid(Blue)) {
                type = "Blue";
            } else if (typeid(T) == typeid(Chili)) {
                type = "Chili";
            } else if (typeid(T) == typeid(Stink)) {
                type = "Stink";
            } else if (typeid(T) == typeid(Green)) {
                type = "Green";
            } else if (typeid(T) == typeid(soy)) {
                type = "soy";
            } else if (typeid(T) == typeid(black)) {
                type = "black";
            } else if (typeid(T) == typeid(Red)) {
                type = "Red";
            } else if (typeid(T) == typeid(garden)) {
                type = "garden";
            }
        }

        Chain(istream& in, const CardFactory* cf);

        int sell() const;

        friend ostream& operator<<(ostream& out, const Chain<Card*>& chain);
};

#endif 
