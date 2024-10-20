/*Ex1b - a3 CSI2372A*/

#include <iostream>
using namespace std;

enum Color { club, diamond, spades, heart };
enum Face { seven, eight, nine, ten, jack, queen, king, ace };

struct Card
{
	Color color;
	Face face;
};

typedef Card Hand[5];

/* testPair() function*/
bool testPair(const Hand& h){
	int NumOfPairs[8] = {0}; // Stores the number of occurances of each face

	for(int i = 0; i < 5; ++i){ // Mark the number of times each face occurs
		NumOfPairs[h[i].face]++; 
	}

	for(int i = 0; i < 8; ++i){
        if(NumOfPairs[i] >= 2){ // Check to see if there is a pair
			return true;
        }
    }
	return false;
}

/*Example of main()*/
int main(){
	bool testPair(const Hand&);
	Hand myHand = { {club,nine}, {diamond, eight}, {spades, ace}, {spades, jack}, {club, ace} };
	cout << "\nI have at least: " << testPair(myHand) << " pair" << endl;

	Hand hand = { {club,nine}, {diamond, nine}, {spades, ten}, {spades, jack}, {heart, ten} };
	cout << "\nI have at least: " << testPair(hand) << " pair" << endl;

	Hand player = { {club,seven}, {diamond, eight}, {spades, nine}, {spades, ten}, {heart, king} };
	cout << "\nI have at least: " << testPair(player) << " pair" << endl;
	return 0;
}



