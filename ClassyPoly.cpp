#include <iostream>
#include <math.h>
#include "ClassyPoly.h"
using namespace std;

///////////////////////////////////////////////////////////////////////////
//
// Public operators and methods


Polynomial Polynomial::dx() const { //derivative 
  Polynomial out = this->derivative();
  return out; 
}

float Polynomial::operator()(const float x) const { //evaluate
  float out = this->evaluate(x);
  return out; 
}

Polynomial Polynomial::operator+(const Polynomial &p) const { //add
  if(p._degree < 0){
    cerr << "Note: Invalid addition" << endl;
    return p;
  }

  Polynomial out = this->add(p);
  return out;
}

Polynomial Polynomial::operator*(const Polynomial &p) const { //multiply 
  if(p._degree < 0){
    cerr << "Note: Invalid multiplication" << endl;
    return p;
  }

  float* coeff = new float[_degree + p._degree + 1];

  for(int x = 0; x <= _degree + p._degree; x++){
    coeff[x] = 0;
  }

  for(int i = 0; i <= _degree ; i++)
    for(int j = 0; j <= p._degree ; j++)
      coeff[i+j] += _coeff[i] * p._coeff[j];
    

  Polynomial out(_degree + p._degree, coeff);

  delete [] coeff;

  return out;
}

void Polynomial::operator=(const Polynomial &p) { //clean up polynomial
  if(p._degree < 0 ){
    cerr << "Note: Invalid Polynomial" << endl;
  }
  else{
    delete [] _coeff;
    _coeff = new float[p._degree + 1];
    _degree = p._degree;
    for(int i = 0; i < p._degree + 1; i++){
      _coeff[i] = p._coeff[i];
    }
  }
  
}

bool Polynomial::operator==(const Polynomial &p) const { //check if equal 
  if(p._degree < 0){
    cerr << "Note: Invalid polynomial" << endl;
    return 0;
  }
  else{
    if(_degree > p._degree){
      return 0;
    }
    else if (_degree < p._degree){
      return 0;
    }

    for(int i = 0; i < _degree + 1; i++){
      if(_coeff[i] - p._coeff[i] > 0.00001)
        return 0;
    }
    return 1;
  }
}

///////////////////////////////////////////////////////////////////////////
//
// Constructors and Destructor
//
// Note: no default constructor
//

Polynomial::Polynomial(const Polynomial &p) {
  if(p._degree < 0){
    cerr << "Note: Invalid polynomial" << endl;
    _degree = -1;
    _coeff = NULL;
  }
  else{ 
    _degree = p._degree;
    _coeff = new float[p._degree + 1];

    for(int i = 0; i < p._degree + 1; i++){
      _coeff[i] = p._coeff[i];
    }

  }
  
}

Polynomial::Polynomial(const int degree, const float coeff[]) {
  if(degree < 0){
    cerr << "Note: invalid Polynomial" << endl;
    _degree = -1;
    _coeff = NULL;
  }
  else{
    _degree = degree;
    _coeff = new float[degree + 1];

    for(int i = 0; i < degree + 1; i++){
      _coeff[i] = coeff[i];
    }
  }

}

Polynomial::~Polynomial() {
  delete [] _coeff;
  _degree = -1; 

}

///////////////////////////////////////////////////////////////////////////
//
// Private Methods
//

float Polynomial::evaluate(const float x) const {
  if(_degree < 0){
    cerr << "Note: degree was less than zero" << endl;
    return NAN;
  }
  float value = 0;
  for(int i = 0; i < _degree + 1; i++){
    value = value * x + _coeff[i];
  }

  return value;
}


Polynomial Polynomial::add(const Polynomial &pIn) const {

  if(pIn._degree < 0){
    cerr << "Note: there was an invalid polynomial" << endl;
    return pIn;
  }

  if(_degree > pIn._degree){
    
    float* coeff = new float[_degree + 1];
    

    for(int i = 0; i < (_degree - pIn._degree); i++){
      coeff[i] = _coeff[i];
    }
    for(int i = _degree - pIn._degree; i < _degree+1; i++){
      coeff[i] = _coeff[i] + pIn._coeff[i - (_degree - pIn._degree)];
    }

    Polynomial pOut(_degree, coeff);
    delete [] coeff;
    return pOut;

  }
  else{
    float* coeff = new float[pIn._degree + 1];
   
    

    for(int i = 0; i < pIn._degree - _degree; i++){
      coeff[i] = pIn._coeff[i];
    }
    for(int i =  pIn._degree - _degree; i < pIn._degree + 1; i++){
      coeff[i] = _coeff[i - (pIn._degree - _degree)] + pIn._coeff[i];
    }

    Polynomial pOut(pIn._degree, coeff);

    delete [] coeff;
    return pOut;
    }

  
}

Polynomial Polynomial::derivative() const {
  if(_degree < 0){
    cerr << "Note: degree was less than 0" << endl;
    Polynomial pOut(-1, NULL);
    return pOut;
  }

  if(_degree == 0){
    float* coeff = new float[1];
    coeff[0] = 0;

    Polynomial pOut(0, coeff);

    return pOut;
  }
  float* coeff = new float[_degree];
  Polynomial pOut(_degree - 1, coeff);

  for(int i = 0; i <= pOut._degree; i++){
    pOut._coeff[i] = _coeff[i] * ((pOut._degree + 1)-i); 
  }

  return pOut;

}


///////////////////////////////////////////////////////////////////////////
//
// Test driver
// Some very limited testing; should test ==
// 

#ifndef MARMOSET_TESTING

int main() {
  float coeff[] = {1, 2, 3, 4};   // x^2 + 2x + 3
  Polynomial p0(1,coeff);
  Polynomial p1(2,coeff);
  Polynomial p2(3,coeff);
  
  cout << "When x = 2.2, " << p0 << " evalates to: " << p0(2.2) << endl << endl;
  cout << "When x = 2.2, " << p1 << " evalates to: " << p1(2.2) << endl << endl;
  cout << "When x = 2.2, " << p2 << " evalates to: " << p2(2.2) << endl << endl;

  Polynomial p = p1 + p2;
  Polynomial q = p1 * p2;											
  cout << "p1 + p2 =  " << p << endl << endl;
  cout << "p1 * p2 =  " << q << endl << endl;
 
  cout << "dp/dx =  " << p.dx() << endl;
  cout << "dq/dx =  " << q.dx() << endl;
 
  return 0;
}

#endif


