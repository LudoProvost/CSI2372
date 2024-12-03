#include "headers/TradeArea.h"
using namespace std;

/**
 * @brief Istream constructor for the TradeArea class.
 */
TradeArea::TradeArea(istream& in, const CardFactory* cf) {
    string cardType;
    
    // Add new cards from the input stream into the trade area.
    while (in >> cardType){
        Card* newCard = cf->createCard(cardType); 
        cardList.push_back(newCard);
    }
}

/**
 * @brief Teturns true if card 'c' can be legally added to the trade area.
 * @param c
 * @return bool
 * 
 */
bool TradeArea::legal(Card* c) const {

    // Iterate through cards in trade area.
    for (Card* card : cardList) {
        if (card->getName() == c->getName()) {
            return true;
        }
    }

    return false;
}

/**
 * @brief Returns and removes a card with corresponding bean name s from the trade area.
 * @param s
 * @return Card*
 * 
 */
Card* TradeArea::trade(string s) {
    Card* c = nullptr;
    list<Card*>::iterator it;

    // Iterate through cards in trade area until a card of type s is found.
    for (it = cardList.begin(); it != cardList.end(); it++) {
        if ((*it)->getName() == s) {
            c = *it;
            cardList.erase(it); 
            
            // c will get returned outside of the loop in case card of type s is never found.
            break; 
        }
    }
    return c;
}

/**
 * @brief Returns the total number of cards in the trade area.
 * @return int
 * 
 */
int TradeArea::numCards() const {
    return cardList.size();
}

/**
 * @brief Adds a card to the trade area.
 * @param c
 * @return TradeArea&
 * 
 */
TradeArea& TradeArea::operator+=(Card* c) {

    cardList.push_back(c); // add card c
    return *this;
}

/**
 * @brief Insertion operator to display all the cards in the trade area.
 * @param out
 * @param ta
 * @return ostream&
 * 
 */
ostream& operator<<(ostream& out, const TradeArea& ta) {
    
    for (auto it = (ta.cardList).cbegin(); it != (ta.cardList).cend(); it++) {
        out << **it << " "; 
    }
    return out;
}

/**
 * @brief Returns the list of cards in the trade area.
 * @return const list<card*>
 */
const list<Card*> TradeArea::getCardList() const {
    return cardList;
}