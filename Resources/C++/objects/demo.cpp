#include "vector.h"

int main(int argc, char *argv[]){ 
  Vector *q = new Vector;           //pointer to a Vector, q (heap: dynamical)
  Vector p;                         //Vector, p              (stack)

  Vector[10];                       // <--- an array of vector objects
  
  q->v[0]=-3; q->v[1]=0; q->v[2]=4; //fill vectors
  p.v[0]=1; p.v[1]=2; p.v[2]=2;

  Vector *a = initialize(1,2,3);    //another way to initialize/fill a vector
  
  cout << endl;
  cout << "q = "; q->vprint(); //print vectors
  cout << "r = ";  p.vprint();
  cout << "a = "; a->vprint();
  cout << endl;

  Vector *r = new Vector;
  Vector *s = new Vector;

  r=q->parity();                    //use parity member function
  s=p.parity();
  cout << "r = -p = "; r->vprint();
  cout << "s = -q = "; s->vprint();
  cout << endl;

  cout << "norm(q) = " << q->norm() << endl; //display norms
  cout << "norm(p) = " << p.norm() << endl << endl;

  cout << "dot(r,s) = " << dot(r,s) << endl; //dot product

  //  Vector *t;
  //  t=cross(r,s);
  //  cout << "cross(r,s) = "; t->vprint(); cout << endl;
  //  delete t; t=0;

  cout << "cross(r,s) = "; cross(r,s)->vprint(); cout << endl;

  q=0; delete q;                    //delete objects & clear pointers 
  r=0; delete r; s=0; delete s;

  return 0; 
} 
