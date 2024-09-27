/*myFile2.cpp : Ex2 a2 CSI2372A*/

#include "myFile2.h"

int main() {
	int myArray[sizeArray] = { 2,4,88,20,3,55,87,134,2,5 };

	cout << "Displaying the unsorted array :" << endl;
	for (int i = 0; i < sizeArray; i++) {
		cout << myArray[i] << " ";
	}
	cout <<  endl << endl;
	sort(myArray, sizeArray);
	cout << "Displaying the sorted array :" << endl;
	for (int i = 0; i < sizeArray; i++) {
		cout << myArray[i] << " ";
	}
	cout << endl;
}

void sort(int a[], int size) {
    for (int i = 1; i < size; i++) {
        int val = a[i]; // element to be inserted
        int j = i - 1;

        // we move all elements between index 0 and j that are greater than val 1 index to the right
        while (a[j] > val && j >= 0) {
            a[j + 1] = a[j];
            j--; // decrement j
        }

        a[j + 1] = val; // insert val at the correct position
    }
}