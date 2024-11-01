
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#include "myFile.h"
#include "Card.h"
#include "CardsSet.h"
#include "Player.h"

//TODO: this function
void Card::write() {
	// print card value
	switch (val) {
		case 1:
			cout << "Ace of ";
			break;
		case 11:
			cout << "Jack of ";
			break;
		case 12:
			cout << "Queen of ";
			break;
		case 13:
			cout << "King of ";
			break;
		default:
			cout << val << " of ";
			break;
	}

	// print card suit
	switch (col) {
		case club:
			cout << "Clubs" << endl;
			break;
		case diamond:
			cout << "Diamonds " << endl;
			break;
		case heart:
			cout << "Hearts " << endl;
			break;
		case spade:
			cout << "Spades " << endl;
			break;
	}
}

void CardsSet::novSet() {

	for (int c = club; c <= spade; c++) { // iterate through suits
		for (int v = 1; v <= 13; v++) { // iterate through numbers
			set[(c * 13) + (v-1)] = Card((color) c, v);
		}
	}

	number = 52; //set number to 0 in case it was already another value
}

void CardsSet::shuffle() {
	// seed the random number generator
	srand(static_cast<unsigned int>(time(0)));

	// swap each position with another, this should create enough randomness
	for (int i = number-1; i > 0; i--) {
		int randVal = rand() % number; // generate a random value to be used as index in set

		// swap current position with random position
		Card temp = set[i];
		set[i] = set[randVal];
		set[randVal] = temp;
	}
}

Card CardsSet::take() {
	Card card;
	// check if set empty
	if (number > 0) {
		card = set[--number]; // take card at the top of the set and decrement number
		
		// print message to match example output
		cout << "You get Card: ";
		card.write();
		cout << endl;
	}

	return card;
}

void CardsSet::put(Card k) {
	// check if set is already full
	if (number != 52) {
		set[number++] = k; // place k after the last element and increment number
	}
}

Card CardsSet::lookIn(int no) {
	// we assume that the instructions of this lab consider index 0 to be "top of the set"
	return set[no - 1];
}

//TODO: this function
int Player::play() {

}

//TODO: this function
int Player::countPoints() {

}

int main() {
	CardsSet packet;
	Player you(packet, false);
	Player me(packet, true);
	char answer[3];
	bool continuous = true;
	cout << "Hello! " << endl;
	while (continuous)
	{
		cout << "A new game? " << endl;
		cin >> answer;
		continuous = answer[0] == 'y';
		if (continuous)
		{
			packet.novSet();
			packet.shuffle();
			packet.take();
			int p1 = you.play();
			if (p1 > 21) {
				cout << "You lost! " << endl;
			}
			else if (p1 == 21) {
				cout << "You won! " << endl;
			}
			else // the computer must play
			{
				int p2 = me.play();
				if (p2 <= 21 && p2 >= p1) {
					cout << "You lost! " << endl;
				}
				else {
					cout << "You won! " << endl;
				}
			}
		}
	}
	return 0;
}


