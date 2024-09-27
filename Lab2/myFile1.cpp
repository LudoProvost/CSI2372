#include <iostream>
using namespace std;

int main(void) {
    int tab[10];
    int* p;
    for (int i = 0; i < 10; i++) {
        tab[i] = i * i;
    }

    cout << tab[2] << endl; // print value 4 before it is replaced by tab[1]

    tab[2] = tab[1]; // tab[2] is set to 1
    
    cout << tab[2] << endl; // print value 1 (1/5)
    
    tab[2] = *(tab + 1); // tab[2] is set to 1 (again)
    
    cout << tab[2] << endl; // print value 1 (2/5)

    *(tab + 2) = tab[1]; // tab[2] is set to 1 (again)

    cout << tab[2] << endl; // print value 1 (3/5)

    *(tab + 2) = *(tab + 1); // tab[2] is set to 1 (again)

    cout << tab[2] << endl; // print value 1 (4/5)

    p = &tab[0]; // p points to tab[0]
    p = tab + 1; // p points to tab[1]
    tab[4] = *p; // tab[4] is set to 1 (the value at p)
    cout << tab[4] << endl; // print value 1 (5/5)
}
