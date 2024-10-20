/*Ex1a - a3 CSI2372A*/

#include <iostream>
using namespace std;

enum Color { club, diamond, spades, heart };
enum Face { seven, eight, nine, ten, jack, queen, king, ace };

struct Card{
	Color color;
	Face face;
};

int main(){ 
	Card game[32];
	int k = 0;

	for(int i = 0; i < 4; ++i){ // For loop that populates struct Card with 32 combinations of cards with different colors and faces
		for(int j = 0; j < 8; ++j){ 
			if(k < 32) { // Prevent out of bounds
				game[k].color = static_cast<Color>(i);
				game[k].face = static_cast<Face>(j);
				k++; // Increments the count by one to keep track of the indicie 
			}	
		}	
	}
}
