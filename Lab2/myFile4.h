/*myFile4.h : Ex4 a2 CSI2372A*/

#include <iostream>
#include <process.h>		//for exit() 
#include <string.h>		//for strcmp, strcpy..
#include <limits.h>		// for INT_MAX 
using namespace std;

const int size_ch=20;		// maximum size of a string 
const int nb_ch=5;		//Number of of strings processed 

void display(char *tab[],int const &nbre); //displays strings
char menu(void);		//displays a menu and return the choice
void replace(char *tab[], int const &nbre, int const &size); //replace one string by an other
void sort(char *tab[], int const &nbre); 	//insertion sort			
