/*Ex2 devoir4 CSI2772A*/


#include <iostream> 
#include "myFile2.h"
using namespace std;


int main() {
    SetInt a; 	// object creation
    int* tab;

    while (a.nbElem() < 5)
    {
        cout << "add an int element" << endl;
        int elem;
        cin >> elem;
        a.add(elem);

    }
    cout << "a contains 10 :" << a.contains(10) << endl;
    cout << "remove 10 " << endl;
    a.remove(10);
    cout << "a contains 10 :" << a.contains(10) << endl;
    cout << "a contains :" << a.nbElem() << " elements " << endl;
    tab = a.tabElem();
    cout << "The elements of a are :" << endl;
    for (int i =0; i<a.nbElem(); i++)
        cout << tab[i] << endl;

    return 0;
}