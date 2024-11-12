#include "headers/Card.h"
using namespace std;

string Card::getName() {
    return name;
}

void Card::print(ostream& out) {
    out << getName()[0] << endl;
}

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

//TODO: unsure if should return -1 for invalid chain lenghts (case 1 and 4).
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