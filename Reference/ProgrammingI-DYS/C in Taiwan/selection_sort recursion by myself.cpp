#include <stdio.h> 
#define MAX 10 
#define swap(a, b) if (a != b) {(*a)^=(*b); (*b)^=(*a); (*a)^=(*b);} 

void selection_sort(int* a, int min, int i,int times); 
int a[MAX] = {3, 7, 9, 1, 4, 0, 8, 6, 2, 5}; 
 
int main(void) {     
	selection_sort(a, 0, 1, 0);     
	for (int i = 0; i < MAX; i++) {         
		printf("%d ", a[i]);     
	}     
	return 0; 
} 

void selection_sort(int *a, int min, int i, int times){
	if(times==MAX-1){
		return;
	}
	if(i==MAX){
		swap(&a[min], &a[times]);
		times++;
		selection_sort(a,times,times+1,times);
		return;
	}
	if(a[min]>a[i]){
		min=i;
		i++;
		selection_sort(a,min,i,times);
	}
	else{
		i++;
		selection_sort(a,min,i,times);
	}
}
