#include <iostream>
#include <cstring>
#include <iomanip>
const int MAX_N = 102;
const int MOD = 10007;

class Matrix {
	public:
		Matrix() {
			row = col = 0;
			memset(mat, 0, sizeof(mat));
		}
		// TODO
		Matrix(int r, int c);

		const int &getrow() {
			return row;
		}
		const int &getcol() {
			return col;
		}
		// TODO
		int *operator[] (const int &x);
		const int *operator[] (const int &x) const {
			return mat[x];
		}
		// TODO
		Matrix operator+ (const Matrix &x) const;
		// TODO: be aware that this function is declared with friend!!!
		friend Matrix operator* (const Matrix &x, const Matrix &y);
		
		void print() {
			for(int i=0;i<row;i++) {
				if(i==0) std::cout << "/";
				else if(i==row-1) std::cout << "\\";
				else std::cout << "|";
				for(int j=0;j<col;j++) {
					std::cout << std::right << std::setw(8) << mat[i][j];
				}
				if(i==0) std::cout << " \\\n";
				else if(i==row-1) std::cout << " /\n";
				else std::cout << " |\n";
			}
		}
	private:
		int mat[MAX_N][MAX_N];
		int row, col;
};

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













