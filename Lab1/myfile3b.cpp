#include <iostream>
# include <vector>

using namespace std;

/* Index search selector function that returns the index of the max value of an array
**
*/
int searchIndex(vector<int> T, int imax) {
	if (T.size() < imax - 1) {
		cout << "Erreur ! Tableau trop petit ! " << endl;
		return -1;
	}
	int res = 0;
	for (int i = 1; i <= imax; i++)
		if (T[i] > T[res]) res = i;
	return res;
}

/* Exchange function that exchanges the values ​​of the arguments
**
*/
void exchange(int& a, int& b) {
	int c;
	c = a; a = b; b = c;
}

/* Sort function with Pass by reference
**
*/

void sort(vector<int>& T) {
	int arrSize = T.size();

	// iterate through the array
	for (int i = 0; i < arrSize-1; i++) {
		int maxIndex = searchIndex(T, arrSize - i - 1); // find index of the largest non-sorted int
		exchange(T[maxIndex], T[arrSize - i - 1]); // place the largest non-sorted int at the end of the unsorted array
	} 

}

/* arrayEntry function to enter values ​​from your table
**
*/
vector<int> arrayEntry() {
	int size;
	cout << " Enter the size of your array: ";
	cin >> size;
	vector<int> res(size, 0);
	cout << " Enter the values ​​of your array: \n";
	for (int i = 0; i < size; i++) {
		cout << " val[ " << i << "] =";
		cin >> res[i];
	}
	cout << "\n";
	return res;
}

/* main
**
*/
int main() {
	vector<int> a;
	a = arrayEntry();
	cout << "My array values are : ";
	for (int i = 0; i < a.size(); i++) {
		cout << "\n" << a[i];
	}
	cout << "\n";

	sort(a);
	cout << "\nMy sorted array values are : ";
	for (int i = 0; i < a.size(); i++) {
		cout << "\n" << a[i];

	}
	cout << "\n";
}

