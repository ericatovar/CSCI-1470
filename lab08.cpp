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
// This program will prompt the use to enter the radius and height of a cone to calculate its volume. The program will also use the user's name to address them when using the program.
/////////////////////////////////////////////////////////////////////

#include <iostream> // to use cin and cout
#include <typeinfo> // to be able to use operator typeid
// Include here the libraries that your program needs to compile
#include <cmath>
#include <iomanip>

using namespace std;

// Ignore this; it's a little function used for making tests
inline void _test(const char *expression, const char *file, int line) {
  cerr << "test(" << expression << ") failed in file " << file;
  cerr << ", line " << line << "." << endl << endl;
}
// This goes along with the above function...don't worry about it
#define test(EXPRESSION)                                                       \
  ((EXPRESSION) ? (void)0 : _test(#EXPRESSION, __FILE__, __LINE__))

// Insert here the prototypes of the functions
double square(int rad);
double volume_cone(int rad, int height);
double round_off(double vol, int digits);
void print_data(string name, int radius, int height, double vol);

// Declare a global constant variable called PI above main() that holds
// value 3.141592
const double PI = 3.141592;

int main() {
  // Declare a variable named name that holds text
  string name;

  // Declares variables named height and radius that hold whole numbers
  int height, radius;

  // Declare a variable named volume that holds double precision real numbers
  double volume;

  // Prompts the user "May I get your first name please?: "
  cout << "May I get your first name please?: ";

  // Read the value from the keyboard and stores it in name
  cin >> name;

  // Prompt the user "Thanks ", name, ", now enter radius and height of the cone
  // please: "
  cout << "\nThanks " << name
       << ", now enter radius and height of the cone please: ";

  // Read the values from the keyboard and stores them in radius and height
  // respectively
  cin >> radius >> height;

  // Call function volume_cone() to calculate the volume of the cone and assign
  // the result to volume
  volume = volume_cone(radius, height);

  // Call function print_data() to print the values entered by the user and the
  // volume of the cone
  print_data(name, radius, height, volume);

  // Do NOT remove or modify the following statements
  cout << endl << "Testing your solution" << endl << endl;
  test(typeid(PI) == typeid(1.));       // Incorrect data type used for PI
  test(PI == 3.141592);                 // Incorrect value used for PI
  test(typeid(name) == typeid(string)); // Incorrect data type used for name
  test(typeid(height) == typeid(1));    // Incorrect data type used for height
  test(typeid(radius) == typeid(1));    // Incorrect data type used for radius
  test(typeid(volume) == typeid(1.));   // Incorrect data type used for volume
  test(fabs(volume_cone(3, 5) - 47.124) <
       0.0001); // Incorrect rounding of volume
  test(fabs(volume_cone(3, 4) - 37.699) <
       0.0001); // Incorrect rounding of volume

  return 0;
}

//************************  Function definition  *************************
// Read the handout carefully for detailed description of the functions that you
// have to implement Calculates the square of the value received
double square(int rad) { return rad * rad; }

// Calculates the volume of the cone using the formula 1 / 3 x Pi x radius^2 x
// height
double volume_cone(int rad, int height) {
  double vol = 1. / 3. * PI * square(rad) * height;
  vol = round_off(vol, 3);
  return vol;
}

// Rounds the value received in the first parameter to the number of digits
// received in the second parameter
double round_off(double vol, int digits) {
  return round(vol * pow(10.0, digits)) / pow(10.0, digits);
}

// Prints the volume of the cone
void print_data(string name, int radius, int height, double vol) {
  cout << fixed << setprecision(3);
  cout << "\nOkay " << name << endl;
  cout << "\nFor the radius: " << radius << " and a height: " << height
       << " the cone's volume is " << vol;
  cout << endl;
}