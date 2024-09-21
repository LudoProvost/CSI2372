#include <iostream>
#include <iomanip>
#include <process.h>
using namespace std;

//Define the variable pi to be used for our calculations
const double Pi = 3.14159;

/*@brief Asks the user for input on what they want to do
*@param void Takes in no parameter
*@return char Returns the users input as a character to be used in main */
char menu(void);

/*@brief Calcualtes the volume of a cylinder using v = pi*raidus^2*height
*@param ray The radius of the cylinder is passed by reference (double const&)
*@param height The height of the cylinder is passed by refernce (double const&)
*@return Double The volume of the cylinder */
double volume(double const& ray, double const& height);


/*@brief Calcualtes the surface area of a disk using a = pi*radis^2
*@param ray The radius of the disk is passed by reference (double const&)
*@return Double Surface area of the disk */
double surface(double const& ray);