#include "headers/CardFactory.h"
using namespace std;

CardFactory* CardFactory::inst = nullptr;

/**
 * @brief creates and returns an instance of CardFactory
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
 * @brief constructor for CardFactory class
 */
CardFactory::CardFactory() {
    deck = new Deck();

    deck->reserve(104);

    // add 20 Blue cards
    for (int i = 0; i < 20; i++) {
        deck->push_back(new Blue);
    }

    // add 18 Chili cards
    for (int i = 0; i < 18; i++) {
        deck->push_back(new Chili);
    }

    // add 16 Stink cards
    for (int i = 0; i < 16; i++) {
        deck->push_back(new Stink);
    }

    // add 14 Green cards
    for (int i = 0; i < 14; i++) {
        deck->push_back(new Green);
    }

    // add 12 soy cards
    for (int i = 0; i < 12; i++) {
        deck->push_back(new soy);
    }

    // add 10 black cards
    for (int i = 0; i < 10; i++) {
        deck->push_back(new black);
    }

    // add 8 Red cards
    for (int i = 0; i < 8; i++) {
        deck->push_back(new Red);
    }

    // add 6 garden cards
    for (int i = 0; i < 6; i++) {
        deck->push_back(new garden);
    }
}

/**
 * @brief returns deck
 * @return Deck
 * 
 */
Deck CardFactory::getDeck() {
    // use mersenne twister generator for randomness 
    random_device rd;
    mt19937 g(rd());
    shuffle(deck->begin(), deck->end(), g);

    return *deck;
}