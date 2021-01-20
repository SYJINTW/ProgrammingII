#include<stdio.h>
#include<string.h>
int main(){
	int n,flag=0;
	char str[100010];
	while(~scanf("%s",str)){
		n=strlen(str);
		flag=0;
		for(int i=0;i<=n/2;i++){
			if(str[i]!=str[n-i-1]){
				flag=1;
				break;
			}
		}
		if(flag)
			printf("No\n");
		else
			printf("Yes\n");
	}
} 
