#include "MatrixTools.h"

void Matrix::Dim(int m) {
  Matrix::NRow=m;  Matrix::NCol=m;
}

void Matrix::Error(){
  cout << "You have attempted to cram a " << 
    "rectangular matrix into a square hole." << endl;
}

void Matrix::MPrint() {
  for(int i=0; i<Matrix::NRow; i++) {
    for(int j=0; j<Matrix::NCol; j++) {
      cout << Matrix::M[i][j] << " ";
    }
    cout << endl;
  }
}

void Matrix::RowSub(int b, int a) {
  for(int i=0; i<Matrix::NCol; i++) {
    Matrix::M[b][i] += -Matrix::M[a][i];
  }
}

void Matrix::RowMult(int a, double x) {
  for(int i=0; i<Matrix::NCol; i++){
    Matrix::M[a][i] = x*Matrix::M[a][i];
  }
}

Matrix *Matrix::LMatMult(Matrix *R) {
  if(Matrix::NCol!=R->NRow){cout << "Mismatched dimensions"
				 << endl;  return 0;}
    Matrix *A = new Matrix;
    A->NRow=Matrix::NRow;
    A->NCol=R->NCol;
    for(int i=0; i<A->NRow; i++) {
      for(int j=0; j<A->NCol; j++) {
	A->M[i][j]=0;
	for(int k=0; k<Matrix::NCol; k++) {
	  A->M[i][j] += Matrix::M[i][k]*R->M[k][j];
	}
      }
    }
    return(A);
    delete A;  A=0;
}

Matrix *Matrix::Transpose() {
  if(Matrix::NRow != Matrix::NCol) {Matrix::Error(); return 0;}
  Matrix *B = new Matrix;
  B->Dim(Matrix::NRow);
  for(int i=0; i<Matrix::NRow; i++) {
    for(int j=0; j<Matrix::NRow; j++) {
      B->M[i][j]=Matrix::M[j][i];
    }
  }
  return(B);
  delete B;  B=0;
}

double Matrix::Det() {
  if(Matrix::NRow != Matrix::NCol) {Matrix::Error(); return 0;}
  double det=0;
  if(NRow==2) {
    det = Matrix::M[0][0]*Matrix::M[1][1]-Matrix::M[1][0]*Matrix::M[0][1];
    return(det);
  }
  else{
    int a;  int flip=-1;
    Matrix *S = new Matrix;
    for(int i=0; i<Matrix::NCol; i++) {  //Stricken Column
    S->Dim(Matrix::NRow-1);
      flip=-flip;
      //Fill sub-matrix.
      for(int m=1; m<Matrix::NRow; m++) {
	for(int n=0; n<Matrix::NCol; n++) {
	  if(n!=i) { 
	    a=n;  if(n>i) {a = n-1;}
	    S->M[m-1][a]=Matrix::M[m][n];
	  }
	}
      }
      det += Matrix::M[0][i]*flip*S->Det();
    }
    delete S;  S=0;
    return(det);
  }
}

Matrix *Matrix::Invert() {
  if(Matrix::NRow != Matrix::NCol) {Matrix::Error(); return 0;}
  if(Matrix::Det()==0) {cout << "Can not invert singular matrix."
			     << endl; return 0;}
  //Initialize Matrices---------------
  Matrix *B = new Matrix;
  B->Dim(Matrix::NRow);
  Matrix *C = new Matrix;
  C->Dim(Matrix::NRow);
  //Fill Matrices---------------------
  for(int i=0; i<Matrix::NRow; i++) {
    for(int j=0; j<Matrix::NRow; j++) {
      B->M[i][j] = 0;
      C->M[i][j] = Matrix::M[i][j];
      if(i==j){B->M[i][j]=1;}
    }
  }
  //Invert----------------------------
  for(int k=0; k<Matrix::NRow; k++) {
    B->RowMult(k,1/C->M[k][k]);
    C->RowMult(k,1/C->M[k][k]);
    for(int l=0; l<Matrix::NRow; l++) {
      if((l!=k)&&(C->M[l][k]!=0)) {
	B->RowMult(l,1/C->M[l][k]);
	C->RowMult(l,1/C->M[l][k]);
	B->RowSub(l,k);
	C->RowSub(l,k);
      }
    }
  }
  //Clean Up-------------------------
  for(int m=0; m<Matrix::NRow; m++) {
    B->RowMult(m,1/C->M[m][m]);
    C->RowMult(m,1/C->M[m][m]);
  }
  return(B);
  delete B;  delete C;
  B=0;  C=0;
}

double Matrix::Trace(){
  if(Matrix::NRow != Matrix::NCol) {Matrix::Error(); return 0;}
  double Trace=0;
  for(int i=0; i< Matrix::NRow; i++) {
    Trace += Matrix::M[i][i];
  }  
  return(Trace);
}

Matrix *Matrix::TProd(Matrix *R) {
  Matrix *A = new Matrix;
  A->NRow=Matrix::NRow*R->NRow;
  A->NCol=Matrix::NCol*R->NCol;
  int a, b;
  for(int i=0; i<Matrix::NRow; i++) {
    for(int j=0; j<R->NRow; j++) {
      for(int k=0; k<Matrix::NCol; k++) {
	for(int l=0; l<R->NCol; l++) {
	  a=i+j*R->NRow;
	  b=k+l*R->NCol;
	  A->M[a][b]=Matrix::M[i][k]*R->M[j][l];
	}
      }
    }
  }
  return(A);
  delete A;  A=0;
}
