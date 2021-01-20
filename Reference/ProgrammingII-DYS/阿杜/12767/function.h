// Author: justin0u0<dancinglinkxalgorithm@gmail.com>
#ifndef FUNCTION_H
#define FUNCTION_H

#include <iostream>
using namespace std;
const int mod = 1000000009;

class Matrix {
private:
  int n;
  long long **matrix;
public:
  // The Default Constructor
  Matrix() {
    n = 0;
    matrix = nullptr;
  }
  // TODO: The Destructor
  ~Matrix();

  // TODO: The Customize Constructor
  Matrix(int n);

  // TODO: Copy contructor
  // Will be trigger when the following condition:
  // Matrix m = ref; -> Call copy contructor to copy from 'ref' to 'm'
  Matrix(const Matrix& ref);

  // TODO: copy assignment,
  // Will be trigger when the following condition:
  // Matrix a;
  // a = ref; -> Call copy assignment to copy from 'ref' to 'a'
  Matrix& operator=(const Matrix& ref);

  // TODO: Overload operator()
  // This operator allow the following code
  // This operator can help you access the data easily
  // 1. cout << m(1, 2) << endl; -> Shorthand of `cout << m.matrix[1, 2] << endl;`
  // 2. m(1, 2) = 100; -> Shorthand of `m.matrix[1, 2] = 100`
  long long& operator()(const int& row, const int& column) const;

  // Utilities functions
  // TODO: Make the matrix identity matrix
  void toIdentity();
  void toZero() {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++)
        matrix[i][j] = 0;
    }
  }

  // TODO: Overload operator *
  Matrix operator*(const Matrix& rhs) const;

  // TODO: Return the matrix power of 'k'
  Matrix power(int k) const;

  friend ostream& operator<<(ostream& os, const Matrix& matrix) {
    for (int i = 0; i < matrix.n; i++) {
      for (int j = 0; j < matrix.n; j++)
        os << matrix(i, j) << ' ';
      os << endl;
    }
    return os;
  }
};

// TODO: Construct a matrix
Matrix constructMatrix(int n);

#endif
