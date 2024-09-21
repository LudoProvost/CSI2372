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
    cout << "\nEnter an Integer: ";
    cin >> userInt;

    cout << "\nnumber in decimal " << dec << userInt << endl;
    cout << "number in octal " << oct << userInt << endl;
    cout << "number in hexa " << hex << userInt << "\n\n";

    printf("number in decimal %d\n", userInt);
    printf("number in octal %o\n", userInt);
    printf("number in hexa %x\n", userInt);

    /*  display a user given real number with  and without power of 10 with 3 significant digits
    */
    cout << "\nEnter a real number: ";
    cin >> userReal;

    cout << fixed << setprecision(3) << userReal << endl;
    cout << hexfloat << userReal << endl;

    /*  display a user given character as a char and as its decimal value (ASCII)
    */
    cout << "\nEnter a character: ";
    cin >> userChar;

    cout << userChar << endl;
    cout << static_cast<int>(userChar) << endl; // for this to print 48 when the input is H, line 25 is needed to set the io manipulator to hex (H = ASCII 72 = HEX 48)
}