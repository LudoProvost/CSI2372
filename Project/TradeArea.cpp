#include "headers/TradeArea.h"
using namespace std;

//TODO: add comments for this constructor
TradeArea::TradeArea(istream& in, const CardFactory* cf) {
    string cardType;

    while (in >> cardType){// add new cards from the stream into the tradearea
        Card* newCard = cf->createCard(cardType); // not sure if this implementation works for what we wanna do
        cardList.push_back(newCard);
    }
}

/**
 * @brief returns true if card c can be legally added to the trade area
 * @param c
 * @return bool
 * 
 */
bool TradeArea::legal(Card* c) const {
    // iterate through cards in trade area
    for (Card* card : cardList) {
        if (card->getName() == c->getName()) {
            return true;
        }
    }

    return false;
}

/**
 * @brief returns and removes a card of type s from the trade area
 * @param s
 * @return Card*
 * 
 */
Card* TradeArea::trade(string s) {
    Card* c = nullptr;
    list<Card*>::iterator it;

    // iterate through cards in trade area until a card of type s is found
    for (it = cardList.begin(); it != cardList.end(); it++) {
        if ((*it)->getName() == s) {
            c = *it;
            cardList.erase(it); //TODO: unsure if this works
            return c; 
        }
    }
}

/**
 * @brief returns the number of cards in the trade area
 * @return int
 * 
 */
int TradeArea::numCards() const {
    return cardList.size();
}

/**
 * @brief adds card to the trade area
 * @param c
 * @return TradeArea&
 * 
 */
TradeArea& TradeArea::operator+=(Card* c) {
    cardList.push_back(c); // add card c
    return *this;
}

/**
 * @brief insertion operator to display trade area
 * @param out
 * @param ta
 * @return ostream&
 * 
 */
ostream& operator<<(ostream& out, const TradeArea& ta) {
    // not sure if similar implimentation such as in hand.cpp could work here
    
    for (auto it = (ta.cardList).cbegin(); it != (ta.cardList).cend(); it++) {
        out << **it << " "; //TODO: not sure if this works. alternative: out << it->getName()[0] << endl;
    }
    return out;
}