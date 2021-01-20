#include<stdio.h>

int main(int argc, char const *argv[])
{
	char s[5];
	for (int i = 0; i < 5; i++) {
		scanf("%c", s + i);
	}
	for (int i = 0; i < 5; i++) {
		printf("%c", 187 - s[i]);
	}
	printf("\n");

	return 0;
}