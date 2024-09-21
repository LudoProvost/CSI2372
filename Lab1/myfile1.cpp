#include "myfile1.h"

int main() {
    // print number of butes for different data types
    cout << "Size in bytes of a character: " << sizeof(char) << endl;
    cout << "Size in bytes of an Integer: " << sizeof(int) << endl;
    cout << "Size in bytes of a float: " << sizeof(float) << endl;
    cout << "Size in bytes of a double: " << sizeof(double) << endl;
    cout << "Size in bytes of a short Integer: " << sizeof(short int) << endl;
    cout << "Size in bytes of an unsigned integer: " << sizeof(unsigned int) << endl;

    int userInt;
    double userReal;
    char userChar;

    /*  display a user given integer in decimal, octal and hexa.
        this can be done using input/output manipulators such as the ones used below.
        Another way to display this would be to use printf with different format specifiers like %d for decimal, %o for octal and %x for hexa.
    */
    // cout << "Enter an Integer: ";
    // cin >> userInt;

    // cout << "number in decimal " << dec << userInt << endl;
    // cout << "number in octal " << oct << userInt << endl;
    // cout << "number in hexa " << hex << userInt << endl;

    /*  display a user given real number with  and without power of 10 with 3 significant digits
    */
    cout << "Enter a real number: ";
    cin >> userReal;

    cout << fixed << setprecision(3) << userReal << endl;
    cout << setprecision(16) << hexfloat << userReal << endl; 

    /*  display a user given character as a char and as its decimal value (ASCII)
    */
    cout << "Enter a character: ";
    cin >> userChar;

    cout << userChar << endl;
    cout << static_cast<int>(userChar) << endl; 
}