
#include "headers/Hand.h"
using namespace std;

/**
 * @brief Istream constructor for the Hand class.
 */
Hand::Hand(istream& in, const CardFactory* cf) {
    string CardType;

    // Enter the stream, then create a new card matching the name of the card provided.
    while (in >> CardType){ 
        Card* newCard = cf->createCard(CardType); 
        cardDeque.push_back(newCard); 
    }
}

/**
 * @brief Returns and removes the top card from the player's hand.
 * @return Card*
 * 
 */
Card* Hand::play() {
    // Save the reference of the top card.
    Card* c = cardDeque.front(); 

    // Remove and return the top card.
    cardDeque.pop_front(); 
    return c;
}

/**
 * @brief Returns but does not remove the top card from the player's hand.
 * @return Card*
 * 
 */
Card* Hand::top() {
    // Return top card of cardDeque.
    return cardDeque.front(); 
}

/**
 * @brief Adds card c to rear of the player's hand.
 * @param c
 * @return Hand&
 * 
 */
Hand& Hand::operator+=(Card* c) {
    
    cardDeque.push_back(c); // add card c
    return *this;
}

/**
 * @brief Returns and removes card at the given index i.
 * @param i
 * @return Card*
 * 
 */
Card* Hand::operator[](int i) {
    if (i < 0 || i >= cardDeque.size()) {
        return nullptr;
    }
    
    auto it = cardDeque.begin();
    advance(it, i);

    // Save reference of the card located at index i.
    Card* c = *it; 

    // Remove the card at that index and return it.
    cardDeque.erase(it);
    return c;
}

/**
 * @brief Getter method to retrieve cardDeque.
 * @return const deque<Card*>&
 */
const deque<Card*>& Hand::getCardDeque() const {
    return cardDeque;
}

/**
 * @brief Insertion operator to display hand on an output stream.
 * @param out
 * @param h
 * @return ostream&
 */
ostream& operator<<(ostream& out, const Hand& h) {
    for (const auto& card : h.getCardDeque()) { 
        
        // Loop over each card stored in cardDeque and use Card's built-in print method.
        card -> print(out); 
        out << " ";
    }
    out << endl;
    return out;
}

/**
 * @brief Returns the total number of cards in the player's hand.
 * @return int
 */
int Hand::numberOfCardsInHand() {
    return cardDeque.size();
}