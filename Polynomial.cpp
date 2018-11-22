#include <iostream>
#include <math.h>

using namespace std;

// The polynomial struct keeps the most significant coeff
// in the first coeff[] element, the second in the second
// and so on.

struct Polynomial {
  int    degree;
  float* coeff;
};

float evaluate(const Polynomial p, const float x) {
  if(p.degree < 0){
    cerr << "Note: degree was less than zero" << endl;
    return NAN;
  }
  float value = 0;
  for(int i = 0; i < p.degree+1; i++){
    value += p.coeff[i]*pow(x,(p.degree-i));
  }

  return value;

}

Polynomial add(const Polynomial p1, const Polynomial p2) {
  Polynomial p3;

  if(p1.degree < 0){
    cerr << "Note: there was an invalid polynomial" << endl;
    return p1;
  }
  else if(p2.degree < 0){
    cerr << "Note: there was an invalid polynomial" << endl;
    return p2;
  }

  if(p1.degree > p2.degree){
    p3.coeff = new float[p1.degree+1];

    for(int i = 0; i < (p1.degree - p2.degree ); i++){
      p3.coeff[i] = p1.coeff[i];
    }
    for(int i = p1.degree-p2.degree; i < p1.degree+1; i++){
      p3.coeff[i] = p1.coeff[i] + p2.coeff[i - (p1.degree-p2.degree)];
    }

    p3.degree = p1.degree;

  }
  else{
    p3.coeff = new float[p2.degree+1];

    for(int i = 0; i < p2.degree - p1.degree; i++){
      p3.coeff[i] = p2.coeff[i];
    }
    for(int i =  p2.degree - p1.degree; i < p2.degree+1; i++){
      p3.coeff[i] = p1.coeff[i-(p2.degree-p1.degree)] + p2.coeff[i];
    }

    p3.degree = p2.degree;
    }

  return p3;

}

Polynomial derivative(const Polynomial pIn) {

  Polynomial p;
  if(pIn.degree < 0){
    cerr << "Note: degree was less than 0" << endl;
    p.degree = -1;
    return p;
  }

  if(pIn.degree == 0){
    p.degree = 0;
    p.coeff = new float[1];
    p.coeff[0] = 0;
    return p;
  }

  p.degree = pIn.degree - 1;

  p.coeff = new float[p.degree+1];

  for(int i = 0; i <= p.degree; i++){
    p.coeff[i] = pIn.coeff[i]*((p.degree+1)-i); 
  }

  return p;
}

int displayPolynomial(const Polynomial p) {
  if (p.degree < 0) {
    cerr << "Parameter p is not a polynomial; p.degree = " << p.degree << endl;
    return -1;
  }
  cout << "\"";
  for (int i = 0; i < p.degree; ++i) {
    if (p.coeff[i] == 1) 
      cout << "x";
    else
      cout << p.coeff[i] << "x";
    if ((p.degree - i) > 1) 
      cout <<  "^" <<  (p.degree - i);
    cout << " + ";
  }
  cout << p.coeff[p.degree] << "\"";
  return 0;
}

#ifndef MARMOSET_TESTING

int main() {
  float coeff[] = {663.618, 360.109, -668.516, 228.778, -494.571, 932.234};   // x^2 + 2x + 3
  float coeff2[] = {-431.653, 567.283}; 
  int degree = 5;
  Polynomial p0;
  Polynomial p1;
  Polynomial p2;
  
  p0.degree = degree;
  p0.coeff = coeff;
  p1.degree = 1;
  p1.coeff = coeff2;
/*
  cout << "When x = 2.2, ";
  displayPolynomial(p0);
  cout << " evalates to: " << evaluate(p0,2.2) << endl << endl;

  cout << "When x = 2.2, ";
  displayPolynomial(p1);
  cout << " evalates to: " << evaluate(p1,2.2) << endl << endl;

  cout << "When x = 2.2, ";
  displayPolynomial(p2);
  cout << " evalates to: " << evaluate(p2,2.2) << endl << endl;
*/

  Polynomial p = add(p0,p1);
  cout << "p1 + p2 =  ";
  displayPolynomial(p);
  cout << endl;

  Polynomial pDer = derivative(p);
  cout << "dp/dx =  ";
  displayPolynomial(pDer);
  cout << endl;

  return 0;
}

#endif
