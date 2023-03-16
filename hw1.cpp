//******************************************************************************
// Team #5             CSCI 1470      Spring 2023                    Homework # 1
// Erica Tovar
// Alejandra Garza
// Write a program that allows the user to convert Pesos and Euros to U.S. dollars. The outputs should display their equivalent U.S. dollar values, and the total of both Pesos and Euros in U.S. dollars.
//******************************************************************************

#include <iostream>				// to be able to use cout
#include <typeinfo>				// to be able to use operator typeid

// Include here all the libraries that you need for your program to compile.
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

int main()
{
  
// ----------------------------- Code STARTS here ------------------------------------------

//---DECLARING VARIABLES---
  
  //Declare DOL2MEX = 18.62 and DOL2EURO = 0.92 to be constant double precision real numbers.
  const double DOL2MEX = 18.62;
  const double DOL2EURO = 0.93;
  
  //Declare pesos and euros to be double precision real numbers.
  double pesos, euros, decidollarp, roundollarsp, decidollare, roundollarse;
  double doublecentdollarsp, doublecentdollarse;
    
  //Declare wholedollarsp, centdollarsp, wholedollarse, centdollarse, wholetotal, and centtotal to be integers.
  int wholedollarsp, centdollarsp, wholedollarse, centdollarse, wholetotal, centtotal;
  
  //Declare additional variables.
  int extra;

  

//---GETTING USER INPUTS---
  
  //Output the statement "Mexican Peso and Euro to U.S. Dollar converter".
  cout << "Mexican Peso and Euro to U.S. Dollar converter\n\n";
  
  //Prompt the user to enter the amount of Mexican Pesos they'd like to convert to dollars.
  cout << "Please enter the amount of Pesos: ";
    
  //Read from keyboard the value entered by the user and assign it to pesos.
  cin >> pesos;
  
  //Prompt the user to enter the amount of Euros they'd like to convert to dollars.
  cout << "Please enter the amount of Euros: ";
  
  //Read from keyboard the value entered by the user and assign it to euros.
  cin >> euros;
  

  
//---ALL CALCULATIONS---

  //Calculate the whole dollars of the amount obtained from converting the pesos by dividing pesos by 18.62.
  wholedollarsp = static_cast<int>(pesos/DOL2MEX);
  
  //Calcualte the cents of the amount obtained from converting the pesos.
  centdollarsp = static_cast<int>(round(((pesos/DOL2MEX) - wholedollarsp) * 100));

  //Calculate the whole dollars of the amount obtained from converting the euros by deviding euros by 0.93.
  wholedollarse = static_cast<int>(euros/DOL2EURO);

  //Calcualte the cents of the amount obtained from converting the euros.
  centdollarse = static_cast<int>(round(((euros/DOL2EURO) - wholedollarse) * 100));
  
  //Add variables centdollarsp and centdollarse, divide by 100 and assign the total to variable extra.
  extra = (centdollarsp + centdollarse)/100;
  
  //Calculate the dollars of the total amount by adding the dollars of pesos and dollars of euros.
  wholetotal = wholedollarsp + wholedollarse + extra;

  //Calculate the cents of the total amount by adding the cents from pesos and cents of euros.
  centtotal = (centdollarsp + centdollarse) % 100;

  

//---FORMATTING OUTPUTS---
  
  //Output the statement "Mexican Peso and Euro to U.S. Dollar converter".
  cout << "\n\nMexican Peso and Euro to U.S. Dollar converter\n\n\n";

  //Format and display the conversion from pesos to U.S. dollars to be displayed by using setw() and to be fixed with a presicion of 2.
  cout << setw(10) << fixed << setprecision(2) << pesos << " pesos:" << setw(10) << wholedollarsp << " US dollars with " << centdollarsp << " cents\n\n";

  //Format and display the conversion from euros to U.S. dollars to be displayed by using setw() and to be fixed with a presicion of 2.
  cout << setw(10) << fixed << setprecision(2) << euros << " euros:" << setw(10) << wholedollarse << " US dollars with " << centdollarse  << " cents\n\n";

  //Format and display the total of U.S. dollars to be displayed by using setw() and to be fixed with a presicion of 2.
  cout << setw(17) << " Total:" << setw(10) << wholetotal << " US dollars with " << centtotal  << " cents\n\n";

// ----------------------------- Code ENDS here --------------------------------------------
  

  
// Do NOT remove or modify the following statements

	cout << endl << "Testing your solution" << endl << endl;
	test(typeid(DOL2MEX) == typeid(1.));			// Incorrect data type used for DOL2MEX
	test(typeid(DOL2EURO) == typeid(1.));			// Incorrect data type used for DOL2EURO
	test(typeid(pesos) == typeid(1.));				// Incorrect data type used for pesos
	test(typeid(euros) == typeid(1.));				// Incorrect data type used for euros
	test(typeid(wholedollarsp) == typeid(1));		// Incorrect data type used for wholedollarsp
	test(typeid(centdollarsp) == typeid(1));		// Incorrect data type used for centdollarsp
	test(typeid(wholedollarse) == typeid(1));		// Incorrect data type used for wholedollarse
	test(typeid(centdollarse) == typeid(1));		// Incorrect data type used for centdollarse
	test(typeid(wholetotal) == typeid(1));			// Incorrect data type used for wholetotal
	test(typeid(centtotal) == typeid(1));			// Incorrect data type used for centtotal
	if (pesos == 230.0 && euros == 24.50)			// Does not pass test 1
	{
		test(wholedollarsp == 12 && centdollarsp == 35);
		test(wholedollarse == 26 && centdollarse == 34);
		test(wholetotal == 38 && centtotal == 69);
	}
	if (pesos == 190.29 && euros == 130.00)				// Does not pass test 2
	{
		test(wholedollarsp == 10 && centdollarsp == 22);
		test(wholedollarse == 139 && centdollarse == 78);
		test(wholetotal == 150 && centtotal == 0);
	}
	if (pesos == 856.70 && euros == 93.07)			// Does not pass test 3
	{
		test(wholedollarsp == 46 && centdollarsp == 1);
		test(wholedollarse == 100 && centdollarse == 8);
		test(wholetotal == 146 && centtotal == 9);
	}
	if (pesos == 241.87 && euros == 42.82)				// Does not pass test 4
	{
		test(wholedollarsp == 12 && centdollarsp == 99);
		test(wholedollarse == 46 && centdollarse == 4);
		test(wholetotal == 59 && centtotal == 3);
	}
	return 0;
}
