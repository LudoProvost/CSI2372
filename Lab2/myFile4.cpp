/*myFile4.cpp : Ex4 a2 CSI2372A*/

#include "myFile4.h"

main()
{
	int i;
	char *chain[nb_ch];		//array of pointers on char
	char choice;			//variable for the choice entered in menu()

	cout << endl << "Enter the 5 character strings ending with a tab and a line return" << endl ;

	for (i=0;i<nb_ch;i++)
		{
		chain[i]=new char[size_ch];		// memory allocation
		cin.getline(chain[i],size_ch,'\t');	//seizure of the string
		cin.ignore(INT_MAX,'\n');		// ignore line return
		}

	display(chain,nb_ch);					

	while(1)
		{
		choice=menu();
	
		switch(choice)
			{
			case '1':	display(chain,nb_ch);
				break;
			case '2':	replace(chain,nb_ch,size_ch);	
				break;
			case '3':	sort(chain,nb_ch);
				break;
			case '4':	exit(0);
			default:	break;
			}
		}
}




/********************************************************************************/
/* Function menu which returns a character corresponding to the user's choice  */
/********************************************************************************/

char menu(void)
{
	char choice;

	cout << endl << endl << "\t\tMenu" << endl <<endl;
	cout << "1) Strings display." <<endl;
	cout << "2) Replacement of a string by an other one"<<endl;
	cout << "3) Sorting strings"<< endl;
	cout << "4) Exit of the program"<<endl<<endl;
	cout << "Your choice :";
	cin >> choice;

	return(choice);

}


/********************************************************************************/
/*Function display which displays the strings*/
/********************************************************************************/
void display(char* tab[], int const& nbre){
	for (int i = 0 ; i < nbre ; i++){
		cout << "The string " << i << " is: " << tab[i] << endl; 
	}
}

/********************************************************************************
*
The replace function that replaces one string by another. 
It takes as arguments an array of pointers on the strings "tab", 
the number of elements of this array of pointers "nbre" and 
the maximum size of the strings "size" 
*
********************************************************************************/

void replace(char* tab[], int const& nbre, int const& size){
	int numero;	//the string to modify

	cout << endl << "Enter the string number to modify: ";
	cin.ignore(INT_MAX,'\n');
	cin >> numero;

	if (numero >= 0 && numero < nbre) { // Check that the number is < 5
		char newString[size];
		cout << "Enter the new string: ";
		cin.ignore(INT_MAX, '\n');
		cin.getline(newString, size);
		strncpy(tab[numero], newString, size); // Replace the old string with a new one
	}else{
		cout << "Invalid index entered." << endl;
	}

 }

/********************************************************************************/
/*Function sort to sort strings */
/********************************************************************************/
void sort(char* tab[], int const& nbre){

	for (int i = 1; i < nbre; ++i) {
        char* key = tab[i];
        int j = i - 1;
        
        while (j >= 0 && strcmp(tab[j], key) > 0) { //Use strcmp to return address of the largest string
            tab[j + 1] = tab[j];
            --j;
        }
        tab[j + 1] = key;
    }
}