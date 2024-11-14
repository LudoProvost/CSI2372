#ifndef CARDFACTORY_H
#define CARDFACTORY_H
#include <random>
#include <algorithm>
using namespace std;

#include "Card.h"
#include "Deck.h"

class CardFactory {
    private:
        CardFactory(); // singleton pattern design
        static CardFactory* inst;
        Deck* deck;
    public:
        static CardFactory* getFactory();
        Deck getDeck();
};

#endif