#include <iostream>
#include <cstring>
#include <iomanip>
#include "function.h"

Matrix::Matrix(int r, int c){
	row = r;
	col = c;
	memset(mat, 0, sizeof(mat)); // initial all the element to 0
}

int *Matrix::operator[] (const int &x){
	return mat[x]; // 回傳一個 pointer
}

Matrix Matrix::operator+ (const Matrix &x) const{
	Matrix result(row, col); // create a new matrix
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			// 這裡的 mat 代表 this 中的矩陣
			result[i][j] = ((mat[i][j] + x[i][j]) % MOD + MOD) % MOD;
		}
	}
	return result;
}

// 因為是 friend 形式，所以可以用外部函數的方式去完成它
// 可以直接使用 x.row x.col y.row y.col
Matrix operator* (const Matrix &x, const Matrix &y){
	Matrix result(x.row, y.col); // create a new matrix
	// 基本的矩陣相乘
	for(int i = 0; i < x.row; i++){
		for(int j = 0; j < y.col; j++){
			// k => x's col and y's row
			for(int k = 0; k < x.col; k++){
				result[i][j] = (result[i][j]+((x[i][k]*y[k][j])%MOD+MOD)%MOD)%MOD;
			}
		}
	}
	return result;
}