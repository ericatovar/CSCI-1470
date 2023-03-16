//******************************************************************************
// Team # 05 Spring 2023 Homework # 2
// Alejandra Garza
// Erica Tovar
// Using your own words, write here a description of what the program does: This
// program receives values from a file and assigns them to different points.
// These points are then calculated finding the semiperimeter and perimeter,
// then the area is given of the length between the 3.
//******************************************************************************

#include <iostream> // to use cin and cout
#include <typeinfo> // to be able to use operator typeid

// Include here the libraries that your program needs to compile
#include <cmath>
#include <fstream>
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
double square(double x);
double round_off(double x, int dig);
void getPoint(ifstream &iFile, double &x, double &y);
double calcLength(double x1, double y1, double x2, double y2);
double semiPerimeter(double L1, double L2, double L3);
double calcArea(double L1, double L2, double L3);
void printDistance(ofstream &oFile, double x1, double y1, double x2, double y2,
                   double distance);

int main() {
  // declare variables
  ifstream inFile;
  ofstream outFile;
  double x1, x2, y1, y2, L1, L2, L3, s, p, area;
  double a1, b1;
  inFile.open("inputhw2.txt");

  // check if file opens properly
  if (!inFile) {
    cout << "File not found" << endl;
    return 1;
  }
  outFile.open("output1.txt");

  // call getPoint to receive the values for x1 and y1
  getPoint(inFile, x1, y1);

  // call getPoint to recieve the valuesfor x2 and y2
  getPoint(inFile, x2, y2);

  // call calcLength to calculate the lenth between the pointsand assign to L1
  L1 = calcLength(x1, y1, x2, y2);

  // call getPoint to receive the values for a1 and b1
  getPoint(inFile, a1, b1);

  // call calcLength to calculate length between two pointsand assign to L2
  L2 = calcLength(x2, y2, a1, b1);

  // call calcLength to calculate length between two pointsand assign to L3
  L3 = calcLength(x1, y1, a1, b1);

  // call semiPerimeter and assign the outcome to s
  s = semiPerimeter(L1, L2, L3);

  // call calcArea and assign the outcomes to area
  area = calcArea(L1, L2, L3);

  // call print Distance for each side
  printDistance(outFile, x1, y1, x2, y2, L1);
  printDistance(outFile, x2, y2, a1, b1, L2);
  printDistance(outFile, x1, y1, a1, b1, L3);

  // close files
  outFile.close();
  inFile.close();

  // Do NOT remove or modify the following statements

  cout << endl << "Testing your solution" << endl << endl;

  test(fabs(round_off(calcLength(1.0, 1.2, 6.0, 6.1), 2) - 7.00) <
       .001); // Incorrect calculation of length
  test(fabs(round_off(calcLength(6.0, 6.1, 3.2, 6.5), 2) - 2.83) <
       .001); // Incorrect calculation of length
  test(fabs(round_off(calcLength(1.0, 1.2, 3.2, 6.5), 2) - 5.74) <
       .001); // Incorrect calculation of length
  test(fabs(calcArea(calcLength(1.0, 1.2, 6.0, 6.1),
                     calcLength(6.0, 6.1, 3.2, 6.5),
                     calcLength(1.0, 1.2, 3.2, 6.5)) -
            7.86) < .001); // Incorrect calculation of area

  test(fabs(round_off(calcLength(1.2, 1.2, 7.6, 4.3), 2) - 7.11) <
       .001); // Incorrect calculation of length
  test(fabs(round_off(calcLength(7.6, 4.3, 9.2, 3.4), 2) - 1.84) <
       .001); // Incorrect calculation of length
  test(fabs(round_off(calcLength(1.2, 1.2, 9.2, 3.4), 2) - 8.30) <
       .001); // Incorrect calculation of length
  test(fabs(calcArea(calcLength(1.2, 1.2, 7.6, 4.3),
                     calcLength(7.6, 4.3, 9.2, 3.4),
                     calcLength(1.2, 1.2, 9.2, 3.4)) -
            5.36) < .001); // Incorrect calculation of area

  test(fabs(round_off(calcLength(1.0, 1.0, 5.0, 5.0), 2) - 5.66) <
       .001); // Incorrect calculation of length
  test(fabs(round_off(calcLength(5.0, 5.0, 9.0, 9.0), 2) - 5.66) <
       .001); // Incorrect calculation of length
  test(fabs(round_off(calcLength(1.0, 1.0, 9.0, 9.0), 2) - 11.31) <
       .001); // Incorrect calculation of length
  test(fabs(calcArea(calcLength(1.0, 1.0, 5.0, 5.0),
                     calcLength(5.0, 5.0, 9.0, 9.0),
                     calcLength(1.0, 1.0, 9.0, 9.0)) -
            0.00) < .001); // Incorrect calculation of area

  return 0;
}

//************************  Function definitions  *************************
// Read the handout carefully for detailed description of the functions that you have to implement

// calculates the squares of the distances of the x and y coordinates.
double square(double x) { return x * x; }
double round_off(double x, int dig) {
  return round(x * pow(10.0, dig)) / pow(10.0, dig);
}

// returns both of x and y rounded to a single decimal place to the caller.
void getPoint(ifstream &iFile, double &x, double &y) {
  iFile >> x >> y;
  x = round_off(x, 1);
  y = round_off(y, 1);
}

// calculates the distance between the coordinates of two points.
double calcLength(double x1, double y1, double x2, double y2) {
  double result;
  result = sqrt(square(x2 - x1) + square(y2 - y1));
  return round_off(result, 10);
}

// calculates the value of the smi perimeter with three lenghts.
double semiPerimeter(double L1, double L2, double L3) {
  return ((1. / 2.) * (L1 + L2 + L3));
}

// calculates the area of the triangle with three legths and by calling
// semiPerimeter().
double calcArea(double L1, double L2, double L3) {
  double s, result;
  s = semiPerimeter(L1, L2, L3);
  result = (s * (s - L1) * (s - L2) * (s - L3));
  result = sqrt(result);
  return round_off(result, 2);
}

// Prints the distances between each pair of coordinates of each point.
void printDistance(ofstream &oFile, double x1, double y1, double x2, double y2,
                   double distance) {
  oFile << "The distance between (" << fixed << setprecision(1) << x1 << ","
        << y1 << ") and (" << x2 << "," << y2 << ") is (" << fixed
        << setprecision(2) << distance << ")" << endl;
}