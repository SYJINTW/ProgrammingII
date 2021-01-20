#include <stdio.h>
#include <stdlib.h>
#include "function.h"

int main() {
	int i, N, offset, *array, **ptr;
	scanf("%d %d",&N, &offset);
	malloc_array(&array, (1+N)*N/2);
	ptr = malloc_ptr(N);
	for(i = 0; i < (1+N)*N/2; i++){
		array[i] = i;
	}
	pointer_ptr_to_array(array,ptr,N);
	for(i = 0; i < N; i++){
		printf("%d\n",*(ptr[i]+(offset)));
	}
	free(ptr);
	free(array);
	return 0;
}
