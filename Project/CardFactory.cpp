#include "headers/CardFactory.h"
using namespace std;

CardFactory* CardFactory::inst = nullptr;

/**
 * @brief Creates and returns a new instance of CardFactory.
 * @return CardFactory*
 * 
 */
CardFactory* CardFactory::getFactory() {
    if (inst == nullptr) {
        inst = new CardFactory();
    }
    return inst;
}

/**
 * @brief Constructor for the CardFactory class.
 */
CardFactory::CardFactory() {
    deck = new Deck();

    deck->reserve(104);

    // Add 20 new Blue cards to the deck.
    for (int i = 0; i < 20; i++) {
        deck->push_back(new Blue);
    }

    // Add 18 new Chili cards to the deck.
    for (int i = 0; i < 18; i++) {
        deck->push_back(new Chili);
    }

    // Add 16 new Stink cards to the deck.
    for (int i = 0; i < 16; i++) {
        deck->push_back(new Stink);
    }

    // Add 14 new Green cards to the deck.
    for (int i = 0; i < 14; i++) {
        deck->push_back(new Green);
    }

    // Add 12 new soy cards to the deck.
    for (int i = 0; i < 12; i++) {
        deck->push_back(new soy);
    }

    // Add 10 new black cards to the deck.
    for (int i = 0; i < 10; i++) {
        deck->push_back(new black);
    }

    // Add 8 new Red cards to the deck.
    for (int i = 0; i < 8; i++) {
        deck->push_back(new Red);
    }

    // Add 6 new garden cards to the deck.
    for (int i = 0; i < 6; i++) {
        deck->push_back(new garden);
    }
}

/**
 * @brief Returns the deck.
 * @return Deck
 * 
 */
Deck CardFactory::getDeck() {

    // Use the mersenne twister generator for randomness in the deck generation.
    random_device rd;
    mt19937 g(rd());
    shuffle(deck->begin(), deck->end(), g);

    return *deck;
}

/**
 * @brief Returns a new card type matching the string value passed through.
 * @param cardName
 * @return Card*
 * 
 */
Card* CardFactory::createCard(const string& cardName) const {
    if (cardName == "Blue") {
        return new Blue;
    } else if (cardName == "Chili") {
        return new Chili;
    } else if (cardName == "Stink") {
        return new Stink;
    } else if (cardName == "Green") {
        return new Green;
    } else if (cardName == "soy") {
        return new soy;
    } else if (cardName == "black") {
        return new black;
    } else if (cardName == "Red") {
        return new Red;
    } else if (cardName == "garden") {
        return new garden;
    }
    return nullptr;
}