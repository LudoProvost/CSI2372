
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


int Player::play() {
	Card card;
	char choice; 
	bool draw = !computer;
	int points = 0;

	
	do{
		card = packet.take(); // Put a card in the hand
		inHand.put(card);

		points = countPoints(); // Sum the players hand value
		cout << "Your score is " << points << " points" << endl;

		if(points >= 21) { // If its 21 or over end the turn
			return points;
		}

		// If the human is playing, prompt for more cards, else the computer will draw until it reaches a hand of 17 points
		if(!computer){
			cout << "Any additional card?";
			cin >> choice;
			draw = (choice == 'y');
		}else{
			draw = (points < 17); // Safe value for the computer to stop drawing cards
		}
	}while(draw);
	return countPoints();
}


int Player::countPoints() {
	int points = 0, ace = 0, val = 0;

	// Look through the hand and sum up the values of each card face
	for (int i = 0; i < inHand.numCards(); ++i) {
		val = inHand.lookIn(i+1).value();
		if (val == 1){
			points += 14; ace++;
		}else {
			points += (val > 10) ? 10 : val;
		}
	}

	// Check if there are any aces and remove 13 * # of aces from the total points if you're over 21
	if(points > 21 && ace > 0){
		for (int j = 0; j < ace; j++){
			points -= 13;
		}
	}
	return points;
}

int main() {
	CardsSet packet;
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
			Player you(packet, false);
			Player me(packet, true);
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


