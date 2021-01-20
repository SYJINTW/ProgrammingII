#include<stdio.h>
#include<string.h>
int main(){
	char str[2010];
	int n,k,flag,count;
	while(scanf("%s", &str[0])!=EOF){
		n = strlen(str);
		count = 0;
		for(int i=1;i<2*n-2;i++){
			k=1;
			if(i%2==0){
				while(str[i/2-k]==str[i/2+k]&&(i/2-k)>=0){
					count++;
					k++;
				}
			}
			else{
				while(str[(i+k)/2]==str[(i-k)/2]&&(i-k)/2>=0){
					count++;
					k+=2;
				}
			}
		}
		printf("%d\n", count);
	}
} 
