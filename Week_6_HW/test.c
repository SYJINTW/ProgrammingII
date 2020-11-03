#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(){
	char a, b;
	a = '1';
	b = 'c';
	if(isdigit(b)){
		printf("is\n");
	}
	else{
		printf("no\n");
	}
}