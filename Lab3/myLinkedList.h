/*Ex2 - a3 CSI2372A*/

#include <iostream>
#include <process.h>
using namespace std;
const int capacity = 20;	// size string

struct 	Evaluation
{
	char student[capacity];
	int grade;
	Evaluation* next;
};

Evaluation* add(Evaluation*, int&);
Evaluation* remove(Evaluation*, int&);
void display(Evaluation*);
int average(Evaluation*, int const&);

