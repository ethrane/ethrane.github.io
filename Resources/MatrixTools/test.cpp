#include <iostream> 
#include <stdlib.h> 
#include <math.h> 
#include <fstream> 
#include <sstream> 
#include <string> 
#include <ctime> 
using namespace std; 

class Matrix{
private:
  double*  M;
  unsigned int nrow,ncol;
public:
  Matrix(unsigned int nrow, usigned int ncol);
  ~Matrix();
}

Matrix::Matrix(unsigned int nrow, unsigned int ncol){
}

Matrix::~Matrx(){
  delete[] M;
}

int main(int argc, char *argv[]){ 
  return 0; 
} 
