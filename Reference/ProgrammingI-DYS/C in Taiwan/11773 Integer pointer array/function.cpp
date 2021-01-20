#include<stdlib.h>
int** malloc_ptr(int array_size){
	int **ptr;
	ptr=(int **)malloc(sizeof(int *)*array_size);
	return ptr;
}
void malloc_array(int **array, int array_size){
	*array=(int *)malloc(sizeof(int )*array_size);
}
void pointer_ptr_to_array(int *array, int **ptr,int N){
	for(int i=0;i<N;i++){
		*(ptr+i)=&array[i*(i+1)/2];
	}
	return;
}
