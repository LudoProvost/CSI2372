#ifndef HAND_H
#define HAND_H

class Hand {
    private:

    public:
        Hand(istream& in, const CardFactory* cf);
        Hand();  //TODO:

        Card* play();
        Card* top();
        
        Hand& operator+=(Card* c);
        Card* operator[](int i);

        friend ostream& operator<<(ostream& out, const Hand& h);
};

#endif 