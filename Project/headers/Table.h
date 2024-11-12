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
        Table(Player* p1, Player* p2, Deck* d, DiscardPile* dp, TradeArea* ta, CardFactory* cf);
        Table(istream& in, const CardFactory* cf);
        ~Table();
        
        bool win(string& playerName);
        void printHand(bool allPlayers);
        Deck getDeck();

        friend ostream& operator<<(ostream& out, Table& t);
};