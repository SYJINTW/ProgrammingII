#include<stdio.h>
#include<math.h>
int main(){
	int month,z;
	double x,y;
	scanf("%d",&month);
	for(int i=0;i<month;i++){
		scanf("%lf%lf",&x,&y);
		z=(int)y/x*100000;
		if(z>=100000){
			if(z%10>=5)
			z=z-(z%10)+10;
		}
		else{
			if(z%10<=5){
				z=z-z%10;
			}
		}
		if(z>=105000){
			printf("%7.2f%% (#`?¡¦)?\n",((double)z/100000-1.0)*100.0);
		}
		else if(z<=95000){
			printf("%7.2f%% (???)b\n",((double)z/100000-1.0)*100.0);
		}
		else if(z>99995){
			printf("%7.2f%% \\^o^/\n",fabs((double)z/100000-1.0)*100.0);
		}
		else
			printf("%7.2f%% \\^o^/\n",((double)z/100000-1.0)*100.0);
	}
}
