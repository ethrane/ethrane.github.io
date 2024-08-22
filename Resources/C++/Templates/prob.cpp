//Definition:P() (Random Probability Generator)                                                                            
double P() {
  double c=-(double)rand() / (double)(RAND_MAX+1);
  return(c);
}
