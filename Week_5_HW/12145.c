#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int S[26];

int main(){
	char x;
	int n, tmp;
	int flag = 0;
	scanf("%d\n", &n);

	if(n != 1){
		for(int i = 0; i < n; i++){
			scanf("%c", &x);
			tmp = (int)x - 97;
			S[tmp] = S[tmp]+1;
			if(S[tmp] > 1){
				flag = 1;
			} else;
		}
	} 
	else flag = 1; //記得考慮 n==1 因為只有一個字母所以都一樣

	if(flag) printf("I'm the god of Knuckles!\n");
	else printf("Different makes perfect\n");
	
	return 0;
}