#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <math.h>

#include "MathTools.h"
using namespace std;

int main(int argc, char *argv[]) {

  cout << endl << "Hello, world." << endl;
  double a=1;
  double b=1;
  double c = Addition(a,b);
  cout << a << " + " << b << " = " << c << endl << endl;

  return 0;
}
