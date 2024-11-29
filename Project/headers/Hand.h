#ifndef HAND_H
#define HAND_H
#include <iostream>
#include <queue>
using namespace std;

#include "Card.h"
#include "CardFactory.h"

class Hand {
    private:
        deque<Card*> cardDeque; // use queue/deque to manage cards in Hand (FIFO)
    public:
        Hand() {}
        Hand(istream& in, const CardFactory* cf);

        Card* play();
        Card* top();
        
        Hand& operator+=(Card* c);
        Card* operator[](int i);
        const deque<Card*>& getCardDeque() const;

        friend ostream& operator<<(ostream& out, const Hand& h);
};

#endif 