#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <math.h>
#include "MatrixTools.h"
using namespace std;

int main(int argc, char *argv[]) {

  cout << endl << "Hello, world." << endl;
  
  Matrix *MyMatrix = new Matrix;
  MyMatrix->Dim(2);
  MyMatrix->M[0][0]=1;  MyMatrix->M[0][1]=3;
  MyMatrix->M[1][0]=2;  MyMatrix->M[1][1]=-1;
  MyMatrix->MPrint();
  cout << endl;

  MyMatrix = MyMatrix->TProd(MyMatrix);
  MyMatrix->MPrint();
  cout << endl;

  //Usage: A->LMatMult(B) = A*B
  MyMatrix = MyMatrix->LMatMult(MyMatrix);
  MyMatrix->MPrint();
  cout << endl;

  double Trace = MyMatrix->Trace();  
  cout << endl << "Trace = " << Trace << endl << endl;

  Matrix *MyOtherMatrix = new Matrix;
  MyOtherMatrix->NRow=2;  MyOtherMatrix->NCol=2;
  MyOtherMatrix->M[0][0]=3;   MyOtherMatrix->M[0][1]=2;
  MyOtherMatrix->M[1][0]=2;   MyOtherMatrix->M[1][1]=2;
  MyOtherMatrix->MPrint();

  cout << "Inverted = " << endl;
  MyOtherMatrix = MyOtherMatrix->Invert();
  MyOtherMatrix->MPrint();
  cout << endl;

  MyOtherMatrix->RowSub(1,0);
  MyOtherMatrix->MPrint();
  cout << endl;

  MyOtherMatrix->RowMult(0,3);
  MyOtherMatrix->MPrint();
  cout << endl;

  MyOtherMatrix =  MyOtherMatrix->Transpose();
  MyOtherMatrix->MPrint();
  cout << endl;

  MyMatrix->Dim(2);
  MyMatrix->M[0][0]=1;  MyMatrix->M[0][1]=1;  MyMatrix->M[0][2]=2;  MyMatrix->M[0][3]=2;
  MyMatrix->M[1][0]=1;  MyMatrix->M[1][1]=1;   MyMatrix->M[1][2]=-1; MyMatrix->M[1][3]=-1;
  MyMatrix->M[2][0]=1;   MyMatrix->M[2][1]=-2;   MyMatrix->M[2][2]=2; MyMatrix->M[2][3]=-2;
  MyMatrix->M[3][0]=1; MyMatrix->M[3][1]=4; MyMatrix->M[3][2]=-3; MyMatrix->M[3][3]=0;
  MyMatrix->MPrint();
  double det = MyMatrix->Det();
  cout << "det = " << det << endl;

  MyMatrix = MyMatrix->Invert();
  MyMatrix->MPrint();

  delete MyMatrix;  delete MyOtherMatrix;
  MyMatrix=0;  MyOtherMatrix=0;

  return 0;
}
