#include<stdio.h>
#include<string.h>
int main(){
	int m,n;
	char s[200000],c[1000],x,y;
	for(int i='a';i<='z';++i){
		c[i]=i;
	}
	scanf("%d%d",&m,&n);
	scanf("%s\n",s);
	while(n--){
		scanf("%c %c\n",&x,&y);
		for(int i='a';i<='z';++i){
			if(c[i]==x)
				c[i]=y;
			else if(c[i]==y)
				c[i]=x;
		}
	}
	for(int i=0;i<m;++i){
		printf("%c",c[s[i]]);
	}
	printf("\n");
}
