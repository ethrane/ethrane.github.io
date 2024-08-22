#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;

//Max Matrix Size is N by N.
//This should be set as small as possible to maximize
//the efficiency of your code.
const int N=3;

class Matrix {
 private:
  void Error();

 public:
  int NRow;
  int NCol;
  double M[N][N];
  double Det();
  Matrix *LMatMult(Matrix *R);
  Matrix *TProd(Matrix *R);
  Matrix *Invert(); 
  Matrix *Transpose();
  double Trace();
  void MPrint();
  void Dim(int x);
  void RowSub(int a, int b);
  void RowMult(int a, double x);
};

