#ifndef TABLE_H
#define TABLE_H
#include "Player.h"
#include "Deck.h"
#include "DiscardPile.h"
#include "TradeArea.h"
#include "CardFactory.h"

class Table {
    private:
        Player* player1;
        Player* player2;
        Deck* deck;
        DiscardPile* discardPile;
        TradeArea* tradeArea;
        CardFactory* cardFactory;
        bool isPlayer1Turn;
    public:
        Table(Player* p1, Player* p2, Deck* d, DiscardPile* dp, TradeArea* ta, CardFactory* cf); // Constructor
        Table(istream& in, const CardFactory* cf); // Istream Constructor
        ~Table(); // Destructor
        
        bool win(string& playerName);
        bool getTurn();
        void changeTurn();
        void printHand(bool allPlayers);
        Deck getDeck();

        friend ostream& operator<<(ostream& out, Table& t);
};

#endif
