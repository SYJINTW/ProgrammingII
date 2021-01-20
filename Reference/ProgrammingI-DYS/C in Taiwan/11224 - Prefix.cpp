#include<stdio.h>
#include<ctype.h>
double prefix(void){
	char c;
	double op1,op2,ans;
	while((c=getchar())==' '||c=='\n')
		continue;
	switch(c){
		case '*':
			printf("( ");
			op1 = prefix();
			printf(" * ");
			op2 = prefix();
			printf(" )");
			ans = op1 * op2;
			break;
		case '-':
			printf("( ");
			op1 = prefix();
			printf(" - ");
			op2 = prefix();
			printf(" )");
			ans = op1 - op2;
			break;
		case '/':
			printf("( ");
			op1 = prefix();
			printf(" / ");
			op2 = prefix();
			printf(" )");
			ans = op1 / op2;
			break;
		case '+':
			printf("( ");
			op1 = prefix();
			printf(" + ");
			op2 = prefix();
			printf(" )");
			ans = op1 + op2;
			break;
		default:
			ans = c - '0';
			printf("%c",c);
	}
	return ans;
}
int main(){
	int time;
	double ans;
	scanf("%d",&time);
	while(time--){
		ans=prefix();
		printf(" = ");
		if((int)ans==ans)
			printf("%.lf\n",ans);
		else
			printf("%.1f\n",ans);
	}
}
