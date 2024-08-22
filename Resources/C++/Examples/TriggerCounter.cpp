#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <math.h>

//This function calculates the clock time in seconds.
double Time(double t1, double t2, double t3) {
  double a = pow(2,32);  double b = pow(2,16);
  return( (t1*a + t2*b + t3)*20E-9 );
}

int main(int argc, char *argv[]) {
  int Trg; 
  //Trigger time is a binary number in three chunks:
  double t1, t2, t3;
  double T;  //T is trigger time in seconds.

  //Load Data
  cout << endl << "Opening: " << argv[1] << endl;
  ifstream infile(argv[1]);
  //  ifstream infile("may04.out");
  if(!infile) {
    cout << "Error: Can't locate input file." << endl;
    exit(1);
  }
  
  int NTrgs=0;   //# of high-E triggers
  int Mask=2;    //Mask is the trigger I am looking for. (2=high-E)
  int UNION;

  //The first time:
  infile >> Trg >> t1 >> t2 >> t3;
  T=Time(t1, t2, t3);
  double T0=T;
  //  cout << T0 << endl;
  UNION = Trg&Mask;
  if(UNION==Mask) {
    NTrgs++;
    //    cout << T << endl;
  }

  //Q-ball 
  //  double Window=500E-6;  //in seconds
  double Window=1;
  //  int QHits=5;  //# Hits required for a Q-ball candidate.
  int QHits=2;
  //Initialize TWindow array and begin search only after QHits.
  double TWindow[500];
  int Candidates=0;

  int TimeOut=1000000;  int Count=0;
  bool done = false;
  while(!done) {
    Count++;
    Trg=0;
    infile >> Trg >> t1 >> t2 >> t3;
    T = Time(t1, t2, t3);
    UNION = Trg&Mask;
    if(UNION==Mask) {
      NTrgs++;
      //QBall***
      TWindow[0]=T;  //Most recent time
      for(int i=1; i<QHits; i++) {
	TWindow[i]=TWindow[i-1];
      }
      if(NTrgs>=QHits) {
	if( (TWindow[0]-TWindow[QHits]) <= Window) {cout << "Candidate." << endl;  Candidates++;} 
      }
      //***QBall
    }
    if(infile.eof() == true) { done = true; }
    if(Count==TimeOut) {done=true;  cout << "Timed Out." << endl;}
  }

  infile.close();

  cout << NTrgs << " triggers / " << T-T0 << " seconds" << endl;
  double Rate=(double)NTrgs/(T-T0);
  cout << "High-E Trigger Rate = " << Rate << " Hz" << endl;
  cout << Candidates << " Q-ball candidates." << endl;

  return 0;
  }
