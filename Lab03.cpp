/////////////////////////////////////////////////////////////////////
//
// Name: Name: Erica Tovar
// Date: 02/03/2023
// Class: CSCI 1470.06
// Semester: Spring 2023
// CSCI 1470 Instructor: Gustavo Dietrich
//
// Using your own words describe below what the program does 
// Program Description: 
// Calculate the total cost of a product by prompting the user to enter the price and tax of the product.
/////////////////////////////////////////////////////////////////////

#include <iostream>				// to be able to use cin  and cout
#include <typeinfo>				// to be able to use operator typeid
#include <cmath>				// to be able to use predefined functions

// Include here all the other libraries that may be required for the program to compile
#include <iomanip>

using namespace std;

// Ignore this; it's a little function used for making tests
inline void _test(const char* expression, const char* file, int line)
{
	cerr << "test(" << expression << ") failed in file " << file;
	cerr << ", line " << line << "." << endl << endl;
}
// This goes along with the above function...don't worry about it
#define test(EXPRESSION) ((EXPRESSION) ? (void)0 : _test(#EXPRESSION, __FILE__, __LINE__))

int main()
{
//Declare variables named price, tax, and total that hold single precision real numbers.
float price, tax, total;
  
//Prompt the user to "Enter the price and tax (%) please: ".
cout << "Enter the price and tax (%) please: ";

//Read the values from the keyboard and store them in price and tax respectively.
cin >> price >> tax;

//Calculate the total cost using the expression Price * (1 + Taxes/100) and assign the resulting value to total.
total = price * (1 + tax/100.);
  
// Round the value of total to ONE decimal digit and reassign the rounded value to total 
total = round(total * 10.)/10.;
  
//Format the output to display the values in fixed format with two decimal digits.
cout << fixed << setprecision(2);
  
//Print a message like the one below:
//
//		�For a price $�, P, �and �, X �% tax, the total cost of the product is $�, T
//
//where P, X, and T are the values corresponding to variables price, tax, and total respectively.
cout << "\nFor price $" << price << " and " << tax << "% tax, the total cost of the product is $" << total << endl << endl;

	// Do NOT remove or modify the following statements
	cout << endl << "Testing your solution" << endl << endl;
	test(typeid(price) == typeid(float));		// Incorrect data type used for price
	test(typeid(tax) == typeid(float));			// Incorrect data type used for tax
	test(typeid(total) == typeid(float));		// Incorrect data type used for total
	if (price == 100.0 && tax == 8.25)			// Incorrect rounding of total
		test(fabs(total - 108.30) < 0.001);

	return 0;		// successful termination
}
