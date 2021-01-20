#include "function.h"

Matrix::~Matrix(){
}

Matrix::Matrix(int n):n(n){
    matrix = new long long*[n];
    for(int i=0;i<n;i++){
        matrix[i] = new long long [n];
    }
    toZero();
}

Matrix::Matrix(const Matrix& ref){
    n=ref.n;
    matrix = new long long* [n];
    for(int i=0;i<n;i++){
        matrix[i] = new long long [n];
    }
    matrix = ref.matrix;
}

Matrix& Matrix::operator=(const Matrix& ref){
    n=ref.n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            matrix[i][j] = ref.matrix[i][j];
    return *this;
}

long long& Matrix::operator()(const int& row,const int&column) const{
    return matrix[row][column];
}

void Matrix::toIdentity(){
    for(int i=0;i<n-1;i++){
        matrix[i][i+1]=1;
    }
    for(int i=0;i<n;i++){
        matrix[n-1][i]=1;
    }
}
Matrix Matrix::operator*(const Matrix& rhs)const{
    Matrix result(n);
    result.toZero();
    for(int row=0;row<n;row++){
        for(int x=0;x<n;x++){
            for(int col=0;col<n;col++){
                result(row,x)+=((*this)(row,col)*rhs(col,x))%mod;
                result(row,x)%=mod;
            }
        }

    }
    return result;
}

Matrix Matrix::power(int k)const{
    Matrix tmp(n);
    tmp = *this;
    if(k==1)return tmp;
    if(k%2==1){
        tmp=power((k-1)/2);
        return tmp*tmp*(*this);
    }
    else{
        tmp=power(k/2);
        return tmp*tmp;
    }
}

Matrix constructMatrix(int n){
    Matrix result(n);
    result.toIdentity();
    return result;
}
