#include "headers/TradeArea.h"
using namespace std;

//TODO: this function
TradeArea::TradeArea(istream&, const CardFactory&) {

}

/**
 * @brief returns true if card c can be legally added to the trade area
 * @param c
 * @return bool
 * 
 */
bool TradeArea::legal(Card* c) {
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
    std::list<Card*>::iterator it;

    // iterate through cards in trade area until a card of type s is found
    for (it = cardList.begin(); it != cardList.end(); it++) {
        if ((*it)->getName() == s) {
            c = *it;
            cardList.erase(it); //TODO: unsure if this works
            break;
        }
    }

    return c;
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
 * @brief insertion operator to display trade area
 * @param out
 * @param ta
 * @return ostream&
 * 
 */
ostream& operator<<(ostream& out, const TradeArea& ta) {
    
    for (auto it = (ta.cardList).cbegin(); it != (ta.cardList).cend(); it++) {
        out << **it << " "; //TODO: not sure if this works. alternative: out << it->getName()[0] << endl;
    }
    return out;
}