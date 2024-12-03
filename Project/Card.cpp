#include "headers/Card.h"
using namespace std;

/**
 * @brief Getter method to retrieve the name of the card.
 * @return string
 * 
 */
string Card::getName() {
    return name;
}

/**
 * @brief Prints the first letter of the name of the card.
 * @param out
 * 
 */
void Card::print(ostream& out) {
    out << getName()[0];
}

/**
 * @brief Returns the number of cards necessary to receive the given number of coins for Blue cards.
 * @param coins
 * @return int
 * 
 */
int Blue::getCardsPerCoin(int coins) {
    int numCards;
    switch(coins) {
        case 1:
            return 4;
        case 2:
            return 6;
        case 3:
            return 8;
        case 4:
            return 10;
        default:
            return -1;
    }
}

/**
 * @brief Returns the number of cards necessary to receive the given number of coins for Chili cards.
 * @param coins
 * @return int
 * 
 */
int Chili::getCardsPerCoin(int coins) {
    int numCards;
    switch(coins) {
        case 1:
            return 3;
        case 2:
            return 6;
        case 3:
            return 8;
        case 4:
            return 9;
        default:
            return -1;
    }
}

/**
 * @brief Returns the number of cards necessary to receive the given number of coins for Stink cards.
 * @param coins
 * @return int
 * 
 */
int Stink::getCardsPerCoin(int coins) {
    int numCards;
    switch(coins) {
        case 1:
            return 3;
        case 2:
            return 5;
        case 3:
            return 7;
        case 4:
            return 8;
        default:
            return -1;
    }
}

/**
 * @brief Returns the number of cards necessary to receive the given number of coins for Green cards.
 * @param coin
 * @return int
 * 
 */
int Green::getCardsPerCoin(int coins) {
    int numCards;
    switch(coins) {
        case 1:
            return 3;
        case 2:
            return 5;
        case 3:
            return 6;
        case 4:
            return 7;
        default:
            return -1;
    }
}

/**
 * @brief Returns the number of cards necessary to receive the given number of coins for soy cards.
 * @param coins
 * @return int
 * 
 */
int soy::getCardsPerCoin(int coins) {
    int numCards;
    switch(coins) {
        case 1:
            return 2;
        case 2:
            return 4;
        case 3:
            return 6;
        case 4:
            return 7;
        default:
            return -1;
    }
}

/**
 * @brief Returns the number of cards necessary to receive the given number of coins for black cards.
 * @param coins
 * @return int
 * 
 */
int black::getCardsPerCoin(int coins) {
    int numCards;
    switch(coins) {
        case 1:
            return 2;
        case 2:
            return 4;
        case 3:
            return 5;
        case 4:
            return 6;
        default:
            return -1;
    }
}

/**
 * @brief Returns the number of cards necessary to receive the given number of coins for Red cards.
 * @param coins
 * @return int
 * 
 */
int Red::getCardsPerCoin(int coins) {
    int numCards;
    switch(coins) {
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 4;
        case 4:
            return 5;
        default:
            return -1;
    }
}

/**
 * @brief Returns the number of cards necessary to receive the given number of coins for garden cards.
 * @param coins
 * @return int
 * 
 */
int garden::getCardsPerCoin(int coins) {
    int numCards;
    switch(coins) {
        case 1:
            return -1;
        case 2:
            return 2;
        case 3:
            return 3;
        case 4:
            return -1;
        default:
            return -1;
    }
}