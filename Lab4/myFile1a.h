/*myFile1a, Ex1 a4 CSI2372A*/

#include <iostream>
using namespace std;

class Course {
    int num;
    int hours;
public:
    Course(int n, int h) : num(n), hours(h){} // Contructor
    int getNum() const {return num;} // Return the number
    int getHours() const {return hours;} // Return the hours
};





