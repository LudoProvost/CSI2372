#include "headers/DiscardPile.h"
using namespace std;

//TODO: this function
DiscardPile::DiscardPile(istream& in, const CardFactory* cf) {

}

Card* DiscardPile::pickUp() {
    Card* c = this->back();

    // remove card from deck
    this->pop_back();
    
    return c;
}

Card* DiscardPile::top() {
    return this->back();
}

void DiscardPile::print(ostream& out) {
    for (int i = 0; i < this->size(); i++) {
        out << *(this->at(i)); //TODO: not sure if this works. alternative: out << d.at(i)->getName()[0] << endl;
    }
    return out;
}

DiscardPile& DiscardPile::operator+=(Card* c) {
    this->push_back();
    return *this;
}

ostream& DiscardPile::operator<<(ostream& out, DiscardPile& dp) {
    // edge case, dp empty
    if (dp.size() == 0) {
        return out;
    }
    
    out << *(dp.back());
    return out;
}