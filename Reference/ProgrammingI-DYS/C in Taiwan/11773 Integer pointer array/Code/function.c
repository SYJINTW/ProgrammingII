#include <stdlib.h>
#include "function.h"
void malloc_array(int **array, int array_size){
    *array = (int *)malloc(sizeof(int)*array_size);
    return;
}
int** malloc_ptr(int array_size){
    int **ptr;
    ptr = (int **)malloc(sizeof(int*)*array_size);
    return ptr;
}
void pointer_ptr_to_array(int *array, int **ptr, int N){
    int i;
    for(i=0;i<N;i++){
        *(ptr + i) = &array[(i + 1) * i / 2];
    }
    return;
}
