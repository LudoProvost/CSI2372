/*myFile3.cpp : Ex3 a2 CSI2372A*/

#include <iostream>
using namespace std;

int** triangleInf(int n)
{
	//YOUR CODE
}

int main() {
	int** tab;
	const int size = 10;
	tab = triangleInf(size);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j <= i; j++)
			cout << tab[i][j] << " ";
		cout << endl;
	}
}