#include <iostream>
#include "myfile2.h" //Include the header file
using namespace std;


//Function to calculate the surface area of a disk
double surface(double const& ray){
    return  Pi * ray * ray;
}

//Function to caluculate the volume of a cylinder
double volume(double const& ray, double const& height){
    return  Pi * ray * ray * height;
}


//Main function
//Calculates the surface area, volume or exits the program depending on which input
//the user provides
int main() {
    char choice;
    int nvolume = 0; //number of times the volume function has been executed
    int nsurface = 0; // number of times the surface function has been executed
    double radius, height;

    while (1){ //Enter loop to start asking user what they want to do
        choice = menu(); //Asks the user what they want to do
        switch (choice){ //Depending on their input provide different options

        //Surface area calculation option
        case '1': cout << endl << "Surface calculation" << endl;
            cout << "Enter the radius: "; cin >> radius;
            nsurface += 1;
            cout << "The surface is: " << surface(radius) << "\n";
            break;

        //Volume calculation option
        case '2': cout << endl << "Volume calculation" << endl;
            cout << " Enter the radius: "; cin >> radius;
            cout << " Enter the height: "; cin >> height;
            nvolume += 1;
            cout << "The volume is: " << volume(radius, height) << '\n';
            break;

        //End program option
        case '3': cout << endl << "Exit the program" << endl;
            cout << "The volume function has been executed " << nvolume << " times" << endl;
            cout << "The surface function has been executed " << nsurface << " times" << endl;
            exit(0);

        default: break;
        }
    }
}

//Function thats called in main which prompts the user for an input
//and returns the choice that the user made
char menu(void) {
    char choice;
    cout << '\n' << "What do you want to do?:" << endl << endl;
    cout << "\t-Calculate the area of a disk from a radius (Press 1)" << endl << endl;
    cout << "\t-Calculate the volume of a cylinder from a radius and a height (Press 2)" << endl << endl;
    cout << "\t-Exit the program (press 3)" << endl << endl;
    cout << "Your choice: ";
    cin >> choice;
    return (choice);
}