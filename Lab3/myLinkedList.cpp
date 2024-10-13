/*Ex2 - a3 CSI2372A*/

#include "myLinkedList.h"

int main()
{
	
	do
	{
		cout << endl << endl << "1) Display  of the complete linked list.\n";
		cout << "2) Insert an element\n";
		cout << "3) Remove an element.\n";
		cout << "4) Calculation of the class average.\n";
		cout << "5) Exit the program.\n" << endl << endl;
		cout << "Your choice ??:";
		cin >> choice;

		switch (choice)
		{
		case 1: display(first);
			break;
		case 2: first = add(first, number);
			break;
		case 3: first = remove(first, number);
			break;
		case 4: average(first, number);
			break;
		case 5: exit(0);
		default:
			break;
		}
	} while (1);
	return 0;
}



/*
*add() Function*
**/
Evaluation* add(Evaluation* p, int& number)
{
	//YOUR CODE COMES HERE
}


/**
*remove() Function*
**/

Evaluation* remove(Evaluation* p, int& number)
{
	//YOUR CODE COMES HERE
}



/**
*display() Function *
**/
void display(Evaluation* p)
{
	//YOUR CODE COMES HERE
}



/**
*average() Function *
***/
int average(Evaluation* p, int const& nbre)
{
	//YOUR CODE COMES HERE
}






