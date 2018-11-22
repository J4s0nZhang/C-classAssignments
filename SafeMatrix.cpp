#include <iostream>
#include "SafeMatrix.h"

// Methods
void SafeMatrix::transpose() {
  int temp = _numRows;
  _numRows = _numCols;
  _numCols = temp; 

  float* data = new (std::nothrow) float[_numCols * _numRows];

  for(int i = 0; i < _numCols; i++){
    for(int j = 0; j < _numRows; j++){
      data[i+j] = MATRIX(*this, j,i );
    }
  }

  delete [] _data;
  _data = data;


}

bool SafeMatrix::appendRow(const int cols, const float data[]) {

  if(_numCols != cols){
    return _nan; 
  }
  _numRows += 1;
  _dataSpaceAllocated = _numRows * _numCols;

  float* dataIn = new (std::nothrow) float[_dataSpaceAllocated];

  for(int j = 0; j < ((_numRows - 1)*_numCols); j++){ //fill new array with old entries
    dataIn[j] = _data[j];
  }

  for(int i = 0; i < _numCols; i++){ //fill the new row with input data
    dataIn[_dataSpaceAllocated + i] = data[i];
  }

  delete[] _data;
  _data = dataIn;

  return 1;
}

bool SafeMatrix::appendColumn(const int rows, const float data[]) {
  if(_numRows != rows){
    return 0;
  }

  _numCols += 1; 
  _dataSpaceAllocated = _numRows * _numCols;

  float* dataIn = new (std::nothrow) float[_dataSpaceAllocated];

  for(int i = 0; i < _numRows; i++){
    for(int j = 0; j < _numCols; j++){
      if(j == _numCols - 1){
        dataIn[i+j] = data[i];
      }
      else{
        dataIn[i+j] = _data[i+j]; 
      }
      
    }
  }

  return 1;

}

Dimensions SafeMatrix::dimensions() const {
  Dimensions d;
  d.rows = _numRows;
  d.cols = _numCols;

  return d;
}

// Operators
float& SafeMatrix::operator()(int i, int j) {
  return MATRIX(*this, i, j); 
}  

SafeMatrix SafeMatrix::operator+(const SafeMatrix& m) const {

  if(_numCols != m._numCols || _numRows != m._numRows){
    return SafeMatrix(-1,-1);
  }


  SafeMatrix dataIn(_numRows, _numCols, 0);

  for(int i = 0; i < _dataSpaceAllocated; i++){
    dataIn._data[i] = _data[i]+ m._data[i];
  }


  return dataIn; 
}

SafeMatrix SafeMatrix::operator*(const SafeMatrix& m) const {
  if(_numCols != m._numRows){
    return SafeMatrix();
  }

  SafeMatrix dataIn(_numRows, m._numCols);
  for(int i = 0; i < _numRows; i++){
    for(int j = 0; j < _numCols; j++){
      for(int z = 0; z < m._numCols; z++){

      }

    }
  }
  return dataIn;
}

void SafeMatrix::operator=(const SafeMatrix& m) {
  _numCols = m._numCols;
  _numRows = m._numRows;
  _dataSpaceAllocated = m._dataSpaceAllocated;
  for(int i = 0; i < _dataSpaceAllocated; i++){
    _data[i] = m._data[i];
  }

}

  // Constructors/Destructor
SafeMatrix::SafeMatrix() {
  _numRows = 0;
  _numCols = 0;
  _dataSpaceAllocated = _numRows * _numCols;
  _data = new (std::nothrow) float[_dataSpaceAllocated]; 

}
SafeMatrix::SafeMatrix(const SafeMatrix& m) {
  _numRows = m._numRows;
  _numCols = m._numCols;
  _dataSpaceAllocated = m._dataSpaceAllocated;
  if(_data = new (std::nothrow) float[_dataSpaceAllocated]){
    for (int i = 0; i < _dataSpaceAllocated; i++){
      _data[i] = m._data[i];
    }
  }

}
SafeMatrix::SafeMatrix(const int rows, const int cols) {
  _numRows = rows;
  _numCols = cols;
  _dataSpaceAllocated = _numRows*_numCols;
  if(_data = new (std::nothrow) float[_dataSpaceAllocated]){
    for (int i = 0; i < _dataSpaceAllocated; i++){
      _data[i] = -1;
    }
  }
}
SafeMatrix::SafeMatrix(const int rows, const int cols, const float initVal) {
  _numRows = rows;
  _numCols = cols;
  _dataSpaceAllocated = _numRows * _numCols;
  if(_data = new (std::nothrow) float[_dataSpaceAllocated]){
    for (int i = 0; i < _dataSpaceAllocated; i++){
      _data[i] = initVal;
    }
  }


}

SafeMatrix::~SafeMatrix() {
    delete [] _data; 
}

std::ostream& operator<<(std::ostream& os, const SafeMatrix& m) {
  INVARIANT_TEST(m._numRows < NOT_A_MATRIX, "ostream::operator<<()");
  if (m._numRows < NOT_A_MATRIX) {
    m.errorMsg("Method ostream::operator<<: attempting to output deleted SafeMatrix");
    abort();
  }
  if (m._numRows == NOT_A_MATRIX) {
    os << "Not-a-Matrix";
    return os;
  }
  if (m._numRows == 0)
    os << "[]";
  for (int i = 0; i < m._numRows; ++i) {
    os << "[";
    for (int j = 0; j < m._numCols; ++j) {
      os << MATRIX(m,i,j);
      if (j < (m._numCols - 1))
        os << ", ";
    }
    os << "]";
    if (i < (m._numRows - 1))
      os << std::endl;
  }
  return os;
}

void SafeMatrix::errorMsg(const char msg[]) const {
  std::cerr << msg << std::endl;
}
