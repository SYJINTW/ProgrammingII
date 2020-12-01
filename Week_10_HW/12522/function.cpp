#include <iostream>
#include <cstring>
#include <iomanip>
#include "function.h"

Matrix::Matrix(int r, int c){
	row = r;
	col = c;
	memset(mat, 0, sizeof(mat));
}

int *Matrix::operator[] (const int &x){
	return mat[x]; // 回傳一個 pointer
}

Matrix Matrix::operator+ (const Matrix &x) const{
	Matrix result(row, col);
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			result[i][j] = ((mat[i][j] + x[i][j]) % MOD + MOD) % MOD;
		}
	}
	return result;
}

Matrix operator* (const Matrix &x, const Matrix &y){
	Matrix result(x.row, y.col);
	for(int i = 0; i < x.row; i++){
		for(int j = 0; j < y.col; j++){
			for(int k = 0; k < x.col; k++){
				result[i][j] = (result[i][j]+((x[i][k]*y[k][j])%MOD+MOD)%MOD)%MOD;
			}
		}
	}
	return result;
}