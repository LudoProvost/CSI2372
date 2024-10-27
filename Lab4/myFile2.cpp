/*Ex2 devoir4 CSI2772A*/


#include <iostream> 
#include "myFile2.h"
using namespace std;

// constructor
SetInt::SetInt(int tab[], int tabSize) {
    elem = new int[size = tabSize];
    
    // copy tab elements into elem
    for (int i = 0; i < size; i++) {
        elem[i] = tab[i];
    }
}

// destructor
SetInt::~SetInt() {
    delete[] elem;
}

// copy constructor
SetInt::SetInt(const SetInt& source) {
    elem = new int[size = source.size];

    // copy elements from source into elem
    for (int i = 0; i < size; i++) {
        elem[i] = source.elem[i];
    }
}

void SetInt::add(int val) {
    // edge case, val already in the set
    if (contains(val)) return;

    // create a new array
    int currentSize = size;
    int* arr = new int[++size];

    // copy elem into the new arr and add val
    for (int i = 0; i < currentSize; i++) {
        arr[i] = elem[i];
    }
    arr[currentSize] = val;

    // delete elem and assign it to point to arr
    delete[] elem;
    elem = arr;
}

void SetInt::remove(int val) {
    // edge case, set is empty
    if (size == 0) return;

    // edge case, set becomes empty after removing val
    if (size == 1 && contains(val)) {
        size--;
        elem = nullptr;
    }

    // parse elem until element is found and copy values into arr
    bool intFound = false;
    int* arr = new int[size-1];

    for (int i = 0; i < size; i++) {
        // true for all iterations that follow after the discovery of the int to remove
        if (intFound) {
            arr[i-1] = elem[i]; // copy values from elem to arr shifted 1 position to the left
        } else {
            intFound = (elem[i] == val); // set intFound to true when int is found
            arr[i] = elem[i]; // copy values from elem to arr at same index
        }
    }
    // delete elem to assign it to point to arr and decrement size only if element was found
    if (intFound) {
        size--;
        delete[] elem;
        elem = arr;
    } else {
        delete[] arr; // delete arr if elem wasn't changed
    }
}

bool SetInt::contains(int val) {
    // parse elem, return true when value is found, else return false
    for (int i = 0; i < size; i++) {
        if (elem[i] == val) return true;
    }
    return false;
}

int SetInt::nbElem() {
    return size; // return size of elem
}

int* SetInt::tabElem() {
    // edge case, set is empty
    if (size == 0) return nullptr;

    // elem not empty, allocate integer array and initialize it to the values in elem
    int* arr = new int[size];
    for (int i = 0; i < size; i++) {
        arr[i] = elem[i];
    }

    return arr;
}

bool SetInt::containsIn(int n, int& pos) {
    return (elem[pos] == n); // return the value of the comparison between n and the value at pos in elem
}

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