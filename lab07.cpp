/////////////////////////////////////////////////////////////////////
//
// Name: Erica Tovar
// Date: 02/17/2023
// Class: CSCI 1470.06
// Semester: Spring 2023
// CSCI 1470 Instructor: Gustavo Dietrich
//
// Using your own words describe below what the program does 
// Program Description: 
// Calculate the surface area for both a cube and a sphere. Do this by obtaining the lengths of the side of the cube and the radius for sphere. The user will be prompted to enter the side and radius values.
/////////////////////////////////////////////////////////////////////

#include <iostream>				// to use cin and cout
#include <typeinfo>				// to be able to use operator typeid

// Include here the libraries that your program needs to compile
#include <iomanip>
#include <cmath>

using namespace std;

// Ignore this; it's a little function used for making tests
inline void _test(const char* expression, const char* file, int line)
{
	cerr << "test(" << expression << ") failed in file " << file;
	cerr << ", line " << line << "." << endl << endl;
}
// This goes along with the above function...don't worry about it
#define test(EXPRESSION) ((EXPRESSION) ? (void)0 : _test(#EXPRESSION, __FILE__, __LINE__))

// Insert here the prototypes of the functions
double square(double userIn);
double cube_surf(double sideSq);
double sphere_surf(double radSq);
double round_off(double area, int digits);

// Declare a global constant variable named PI above main() that holds value 3.141592
const double PI = 3.141592;

int main()
{
// Declare variables named side, radius, s_cube, and s_sphere that hold double precision real numbers
double side, radius, s_cube, s_sphere;
  
// Prompt the user to "Enter side of cube : "
cout << "Enter side of cube: ";
  
// Read from keyboard the value entered by the user and assign it to side
cin >> side;
  
// Prompt the user to "Enter radius of sphere : "
cout << "Enter radius of sphere: ";
  
// Read from keyboard the value entered by the user and assign it to radius
cin >> radius;
  
// Call cube_surf() to calculate the surface of the cube and assign the result to s_cube
s_cube = cube_surf(side);
  
// Call sphere_surf() to calculate the surface of the sphere and assign the result to s_sphere
s_sphere = sphere_surf(radius);

// Clear the screen
system("clear");
  
// Format the output to display the numbers in fixed format with two decimal digits
cout << fixed << setprecision(2);
  
// Display on the screen the message
//	   "The surface area of a cube of sides ", side,   " is ", s_cube
//	"The surface area of a sphere of radius ", radius, " is ", s_sphere
// Use 39 columns for text and 6 columns for the values.
cout << setw(39) << "The surface are of a cube of sides " << setw(6) << side << " is " << setw(6) << s_cube;
cout << endl << endl << setw(39) << "The surface area of a sphere of radius " << setw(6) << radius << " is " << setw(6) << s_sphere;


// Do NOT remove or modify the following statements
	cout << endl << "\nTesting your solution" << endl << endl;
	test(typeid(side) == typeid(1.));						// Incorrect data type used for side
	test(typeid(radius) == typeid(1.));						// Incorrect data type used for radius
	test(typeid(s_cube) == typeid(1.));						// Incorrect data type used for s_cube
	test(typeid(s_sphere) == typeid(1.));					// Incorrect data type used for s_sphere
	test(fabs(cube_surf(3.36) - 67.74) < 0.001);			// Incorrect rounding of value returned by cube_surf() 
	test(fabs(cube_surf(3.37) - 68.14) < 0.001);			// Incorrect rounding of value returned by cube_surf()
	test(fabs(sphere_surf(4.23) - 224.85) < 0.001);			// Incorrect rounding of value returned by sphere_surf()
	test(fabs(sphere_surf(4.29) - 231.27) < 0.001);			// Incorrect rounding of value returned by sphere_surf()

	
	return 0;
}



//************************  Function definition  *************************
// Read the handout carefully for detailed description of the functions that you have to implement
// Calculate the square of the value received
double square(double userIn){
  return userIn * userIn;
}

// Calculate the surface area of the cube using the formula 6 x side^2 (six times the square of the side of the cube)
double cube_surf(double sideSq){
  sideSq = square(sideSq);
  return round_off(6 * sideSq, 2);
}

// Calculate the surface area of the sphere using the formula 4 x Pi x radius^2 (four times Pi times the square of the radius of the sphere)
double sphere_surf(double radSq){
  radSq = square(radSq);
  return round_off(4 * PI * radSq, 2);
}

// Rounds the value received in the first parameter to the number of digits received in the second parameter
double round_off(double area, int digits){
  return round(area * pow(10.0, static_cast<double>(digits))) / pow(10.0, static_cast<double>(digits));
}