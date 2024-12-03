#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
using namespace std;

#include "CardFactory.h"
#include "Chain.h"
#include "Hand.h"

class Player {
    private:
        string name;
        int coins;
        Hand* hand;
        vector<Chain_Base*> chains;
        bool boughtThirdChain;
    public:
        Player(string& n); // Constructor
        Player(istream& in, const CardFactory* cf); // Istream Constructor
        
        string getName() const;
        int getNumCoins() const;
        int getMaxNumChains() const;
        int getNumChains() const;
        void buyThirdChain();
        bool getBoughtThirdChain();
        void printHand(ostream& out, bool allCards);
        void drawCard(Card* c);
        bool play();
        bool handEmpty();
        Chain_Base* createChain(Card* c);
        int tradeChain();
        Card* discardCard(int i);

        bool addCardToChain(Card* c); 
        int getNumCardsInHand() const;

        Chain_Base& operator[](int i) const;
        Player& operator+=(int n);
        friend ostream& operator<<(ostream& out, const Player& p);
};

#endif