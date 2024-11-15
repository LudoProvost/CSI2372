#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
using namespace std;

#include "CardFactory.h"
#include "Chain.h"
#include "Hand.h"

//TODO: this class
class Player {
    private:
        std::string name;
        int coins;
        Hand* hand;
        //TODO: add vector of chains once Chain is implemented.
        bool boughtThirdChain;
    public:
        Player(std::string& n);
        Player(std::istream& in, const CardFactory* cf);
        
        std::string getName();
        int getNumCoins();
        int getMaxNumChains();
        int getNumChains();
        void buyThirdChain();
        void printHand(ostream& out, bool allCards);

        Chain& operator[](int i);
        Player& operator+=(int n);
        friend ostream& operator<<(ostream& out, const Player& p);
};

#endif