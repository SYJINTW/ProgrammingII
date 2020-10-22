#include <stdio.h>
#include <string.h>

#define k 1001

char S[k];
char P[k];
int pre[k];
int S_len, P_len;

void prefix(void){
	int sum = 0;
	int i, j;

	//init pre[]
	for(int i = 0; i < k; i++){
		pre[i] = 0;
	}

	//compare
	for(i = 0; i < S_len; i++){
		for(j = 0; j < P_len; j++){
			if(S[i+j] != P[j]) break;
			else;
		}

		//if all the same
		if(j == P_len){
			pre[i+1] = pre[i] + 1;
		} 
		else{
			pre[i+1] = pre[i];
		}
	}

	/*
	printf("\n");
	for(int h = 0; h <= S_len; h++){
		printf("%d ", pre[h]);
	}
	printf("\n");
	*/
}

int main(){
	int n, a, b, max, tmp;
	while(scanf("%s %s", S, P) != EOF){
		S_len = strlen(S);
		P_len = strlen(P);
		max = 0;
		if(S_len >= P_len){
			//create prefix_sum
			prefix();

			//input how many lines
			scanf("%d", &n);
			while(n--){
				//input range
				scanf("%d%d", &a, &b);
				//check if range > P_len
				if(b-a > P_len){
					tmp = pre[b-(P_len-1)] - pre[a-1];
					if(tmp > max) max = tmp;
					else;
				} else;
			}
		}
		else{
			scanf("%d", &n);
			while(n--){
				scanf("%d%d", &a, &b);
			}
		}
		printf("%d\n", max);
	}
}

/*
abababa aba
1
1 7
-> 3
ababaaaaba ba
5
8 9
2 5
6 7
6 6
2 4
-> 2
abbababaaa b
6
1 7
4 6
7 7
10 10
3 10
1 1
-> 4
*/
