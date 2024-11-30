#ifndef TRADEAREA_H
#define TRADEAREA_H
#include <iostream>
#include <cstdlib>
#include <list>
using namespace std;

#include "CardFactory.h"
#include "Card.h"

//TODO: this class
class TradeArea {
    private:
        list<Card*> cardList;
    public:
        TradeArea(istream&, const CardFactory*);
        TradeArea() {};

        bool legal(Card* c) const;
        Card* trade(string s);// TODO: make const? Card* trade(const string& s);
        int numCards() const;
        const list<Card*> getCardList() const;

        TradeArea& operator+=(Card* c);

        friend ostream& operator<<(ostream& out, const TradeArea& ta);
};

#endif
