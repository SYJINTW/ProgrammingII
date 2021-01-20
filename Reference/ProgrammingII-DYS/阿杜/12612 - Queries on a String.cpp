#include<stdio.h>
#include<string.h>
int main(){
	int T,from,to,t;
	char *temp1,*temp2,*temp3,*temp4,str[100000],temp[100000];
	scanf("%s",str);
	scanf("%d",&T);
	while(T--){
		strcpy(temp,str);
		scanf("%d%d%d",&from,&to,&t);
		t%=(to-from+1);
		strcpy(str+from-1,temp+to-t);
		strcpy(str+from-1+t,temp+from-1);
		strcpy(str+to,temp+to);
	}
			printf("%s\n",str);
}
