#include <stdio.h> 
#define MAX 3 
 
typedef struct {    
	int n, from, to, temp; 
} Record; 
Record stack[MAX]; 
int top = -1; 
 
void move_hanoi(int n, int from, int to, int temp); 
 
int main(void) { 
    move_hanoi(MAX, 1, 3, 2);     
	return 0; 
} 
 
void move_hanoi(int n, int from, int to, int temp) {     
	stack[++top] = (Record) {n, from, to, temp};     
	while (top != -1) { 
	    Record record = stack[top--];
	        if (record.n == 1 || record.temp == -1) {             
				printf("Move disk %d from %d to %d\n", record.n, record.from, record.to);
				continue;
	        }
	    stack[++top] = (Record) {record.n - 1, record.temp, record.to, record.from};         
		stack[++top] = (Record) {record.n, record.from, record.to, -1};         
		stack[++top] = (Record) {record.n - 1, record.from, record.temp, record.to};
    }
} 
