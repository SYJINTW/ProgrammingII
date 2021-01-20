#define COLUMN 5
#include<stdio.h>

void sortArray(int R, int (*array)[COLUMN]){
	int temp;
	for(int i=0;i<R;i++){
		for(int j=0;j<COLUMN;j++){
			for(int k=0;k<COLUMN-j-1;k++){
				if(array[i][k]>array[i][k+1]){
					temp=array[i][k];
					array[i][k]=array[i][k+1];
					array[i][k+1]=temp;
				}
			}
		}
	}
}
