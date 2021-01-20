#include<stdio.h>
int main(){
	int i,n,hulu,pair,value[14]={0};
	scanf("%d",&n);
	char c,d,cards[15];
	d=getchar();
	while(n--){
		i=0;
		pair=0,hulu=0;
		for(int j=0;j<14;j++){
			value[j]=0;
		}
		while((c=getchar())!='\n'){
			cards[i]=c;
			if(cards[i]>'0'&&cards[i]<='9'){
				value[cards[i]-'0']++;
			}
			else if(cards[i]=='A'){
				value[0]++;
			}
			else if(cards[i]=='J'||cards[i]=='K'){
				value[cards[i]-'A'+2]++;
			}
			else if(cards[i]=='Q')
				value[13]++;
			i++;
		}
		for(int j=0;j<14;j++){
			if(value[j]==2){
				pair=1;
			}
			else if(value[j]==3){
				hulu=1;
			}
		}
		if(pair&&hulu){
			printf("YES\n");
		}
		else
			printf("NO\n");
	}
}

