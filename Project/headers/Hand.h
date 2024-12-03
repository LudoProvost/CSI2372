#ifndef HAND_H
#define HAND_H
#include <iostream>
#include <queue>
using namespace std;

#include "Card.h"
#include "CardFactory.h"

class Hand {
    private:
        deque<Card*> cardDeque; // Use queue/deque to manage cards in Hand (FIFO)
    public:
        Hand() {} // Constructor
        Hand(istream& in, const CardFactory* cf); // Istream Constructor

        Card* play();
        Card* top();
        
        Hand& operator+=(Card* c);
        Card* operator[](int i);
        const deque<Card*>& getCardDeque() const;
        int numberOfCardsInHand();

        friend ostream& operator<<(ostream& out, const Hand& h);
};

#endif 