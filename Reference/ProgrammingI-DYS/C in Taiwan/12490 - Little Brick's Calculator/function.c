#include<ctype.h>
int solver(int **ptr, int *sum, char *s){
	int i=0,j=0,temp=0,neg=0;
	while(*(s+i)!='\0'){
		temp=0;
		neg=0;
		while(isdigit(*(s+i))){
			if(neg==0&&*(s+i-1)=='-')	neg=1;
			temp*=10;
			temp+=*(s+i)-'0';
			i++;
		}
		if(neg)
			temp=-temp;
		if(isdigit(*(s+i-1))){
			**(ptr+j)=temp;
			j++;
		}
		*sum+=temp;
		i++;
	}
	return j;
}
