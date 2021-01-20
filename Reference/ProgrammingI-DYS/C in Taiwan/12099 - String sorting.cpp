#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cmp_str(const void *a,const void *b){
	const char *la=(const char*)a;
	const char *lb=(const char*)b;
	return strcmp(la,lb);
}
char str[200010][110];
int main(){
	int i=0;
	char temp[110];
	while(~scanf("%s",str[i]))	i++;
	qsort(str,i,sizeof(char)*110,cmp_str);
	for(int j=0;j<i;j++){
		printf("%s\n",str[j]);
	}
}
