#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

class Vector {
 public:
  double v[3];
  double norm();
  Vector *parity();
  Vector *cross(Vector *x, Vector *y);
  void vprint();
};

double Vector::norm(){
  return sqrt(v[0]*v[0]+v[1]*v[1]+v[2]*v[2]);
}

void Vector::vprint(){
  cout << v[0] << " " << v[1] << " " << v[2] << endl;
}

Vector *Vector::parity(){
  Vector *u = new Vector;
  u->v[0]=-v[0]; u->v[1]=-v[1]; u->v[2]=-v[2];
  return u;
}

Vector *initialize(double x, double y, double z){
  Vector *u = new Vector;
  u->v[0]=x; u->v[1]=y; u->v[2]=z;
  return u;
}

double dot(Vector *x, Vector *y){
  return(x->v[0]*y->v[0]+x->v[1]*y->v[1]+x->v[2]*y->v[2]);
}

Vector *cross(Vector *x, Vector *y){
  Vector *u = new Vector;
  u->v[0] = x->v[1]*y->v[2] - x->v[2]*y->v[1];
  u->v[1] = x->v[0]*y->v[2] + x->v[2]*y->v[0];
  u->v[2] = x->v[0]*y->v[1] - x->v[1]*y->v[0];
  return u;
}
