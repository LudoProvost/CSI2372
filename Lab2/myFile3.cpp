/*myFile3.cpp : Ex3 a2 CSI2372A*/

#include <iostream>
using namespace std;

int** triangleInf(int n){

	int** tab = new int*[n]; // Create array of "pointers to ints" of size n
    
    for(int i = 0; i < n; ++i){ // Create new array for each element in tab to point to
        tab[i] = new int[i + 1];
        
        for(int j = 0; j <= i; ++j){
            if(j == 0 || j == i){ 
                tab[i][j] = 1; // The first and last elements of each row are set to 1
            }else{ 
                tab[i][j] = tab[i-1][j-1] + tab[i-1][j]; // Everyother element is the sum of the two elements above it 
            }
        }
    }
    return tab;
}

int main() {
	int** tab;
	const int size = 10;
	tab = triangleInf(size);

	for (int i = 0; i < size; i++){
		for (int j = 0; j <= i; j++)
			cout << tab[i][j] << " ";
		cout << endl;
	}
}