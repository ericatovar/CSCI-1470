/////////////////////////////////////////////////////////////////////
//
// Name: Erica Tovar
// Date: 02/10/2023
// Class: CSCI 1470.06
// Semester: Spring 2023
// CSCI 1470 Instructor: Gustavo Dietrich
//
// Using your own words describe below what the program does 
// Program Description: 
// Write a program that will get the sine and cosine of angles and add them together. The results will be displayed with three decimal digits.
/////////////////////////////////////////////////////////////////////

#include <iostream>							// for std I/O (cin, cout)
#include <typeinfo>				// to be able to use operator typeid
// Include here all the other libraries that required for the program to compile
#include <cmath>
#include<iomanip>

using namespace std;

// Ignore this; it's a little function used for making tests
inline void _test(const char* expression, const char* file, int line)
{
	cerr << "test(" << expression << ") failed in file " << file;
	cerr << ", line " << line << "." << endl << endl;
}
// This goes along with the above function...don't worry about it
#define test(EXPRESSION) ((EXPRESSION) ? (void)0 : _test(#EXPRESSION, __FILE__, __LINE__))

int  main( )
{
	// Declares constant PI:3.141592
const float PI = 3.141592;
  
	// Declares variable name that holds text
string name;

	// Declares variables alpha,beta,sina,cosb, and total that hold double precision real numbers
double alpha, beta, sina, cosb, total;
  
	// Prompts the user to "Please enter your full name: "
cout << "Please enter your full name: ";

  
	// Reads the full name from keyboard and stores it in the corresponding variable
getline(cin, name);
  
	// Prompts the user to "Please enter angle alpha: "
cout << "\nPlease enter angle alpha: ";

	// Reads the value from the keyboard and stores it in the corresponding variable
cin >> alpha;
  
	// Prompts the user to "Please enter angle beta: "
cout << "\nPlease enter angle beta: ";

	// Reads the value from the keyboard and stores it in the corresponding variable
cin >> beta;
  
	// Displays "Thanks ", name
cout << "\nThanks " << name << endl << endl << endl << endl;

	// Calculates the sine of alpha and the cosine of beta, and stores the results in the corresponding variables
sina = sin(alpha * PI / 180.0);
cosb = cos(beta * PI / 180.0);

	// Calculates the total as the addition of the sine and the cosine and stores it in the corresponding variable
sina = round(sina * 1000.)/1000.;
cosb = round(cosb * 1000.)/1000.;
total = sina + cosb;

	// Formats the output to display the values in fixed format with three decimal digits
cout << fixed << setprecision(3);
  
	// Prints a message like the one below:
	// Using 23 columns displays "sine of alpha: ", using 6 columns displays sina
  
	// Using 23 columns displays "+ cosine of beta: " , using 6 columns displays cosb

	// Using 30 columns displays "-------"

	// Using 23 columns displays "total: ",  using 6 columns displays total
cout << setw(23) << "sine of alpha: " << setw(6) << sina << endl;
cout << setw(23) << "+ cosine of beta: " << setw(6) << cosb << endl;
cout << setw(30) << "-------" << endl;
cout << setw(23) << "total: " << setw(6) << total << endl << endl;


	// Do NOT remove or modify the following statements
	cout << endl << "Testing your solution" << endl << endl;
	test(typeid(name) == typeid(string));		// Incorrect data type used for name
	test(typeid(alpha) == typeid(1.));			// Incorrect data type used for alpha
	test(typeid(beta) == typeid(1.));			// Incorrect data type used for beta
	test(typeid(sina) == typeid(1.));			// Incorrect data type used for sina
	test(typeid(cosb) == typeid(1.));			// Incorrect data type used for cosb
	test(typeid(total) == typeid(1.));			// Incorrect data type used for total
	if (alpha == 33. && beta == 33.)
		test(fabs(total - 1.384) < 0.0001);		// Incorrect rounding
	if (alpha == 66.45 && beta == 66.45)
		test(fabs(total - 1.317) < 0.0001);		// Incorrect rounding
	if (alpha == 87.33 && beta == 87.33)
		test(fabs(total - 1.046) < 0.0001);		// Incorrect rounding
	if (alpha == 25.76 && beta == 25.76)
		test(fabs(total - 1.336) < 0.0001);		// Incorrect rounding
	if (alpha == 25.89 && beta == 25.89)
		test(fabs(total - 1.337) < 0.0001);		// Incorrect rounding

    return 0;								//  Successful completion
}

