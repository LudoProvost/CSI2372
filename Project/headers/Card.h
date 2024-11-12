#include <iostream>
#include <fstream>
using namespace std;

class Card {
    private: 
        string name;
    public:
        Card(string name) : name(name) {}
        
        virtual int getCardsPerCoin(int coins);
        virtual string getName();
        virtual void print(ostream& out);

        friend ostream& operator<<(ostream& out, Card& c) {
            c.print(out);
            return out;
        }
};

class Blue: public virtual Card {
    public:
        Blue() : Card("Blue") {}
        int getCardsPerCoin(int coins);
};

class Chili: public virtual Card {
    public:
        Chili() : Card("Chili") {}
        int getCardsPerCoin(int coins);
};

class Stink: public virtual Card {
    public:
        Stink() : Card("Stink") {}
        int getCardsPerCoin(int coins);
};

class Green: public virtual Card {
    public:
        Green() : Card("Green") {}
        int getCardsPerCoin(int coins);
};

class soy: public virtual Card {
    public:
        soy() : Card("soy") {}
        int getCardsPerCoin(int coins);
};

class black: public virtual Card {
    public:
        black() : Card("black") {}
        int getCardsPerCoin(int coins);
};

class Red: public virtual Card {
    public:
        Red() : Card("Red") {}
        int getCardsPerCoin(int coins);
};

class garden: public virtual Card {
    public:
        garden() : Card("garden") {}
        int getCardsPerCoin(int coins);
};
