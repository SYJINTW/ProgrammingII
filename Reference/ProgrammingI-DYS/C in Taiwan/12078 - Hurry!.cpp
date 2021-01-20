#include<stdio.h>
int main(){
	int T,K,N;
	int urinal[3010];
	int j_min,max_i,max_min,Li,Ri,cur_j;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&N,&K);
		urinal[0]=urinal[N+1]=1;
		for(int i=1;i<=N;i++){
			urinal[i]=0;
		}
		for(int i=1;i<=K;i++){
			max_i=0;
			max_min=-1;
			for(int j=1;j<=N;j++){
				Li=0,Ri=0;
				if(urinal[j])
					continue;
				cur_j=j;
				while(!urinal[--cur_j])
					Li++;
				cur_j=j;
				while(!urinal[++cur_j])
					Ri++;
				j_min=Li>Ri?Ri:Li;
				if(j_min>max_min){
					max_min=j_min;
					max_i=j;
				}
			}
			urinal[max_i]=1;
		}
	printf("%d\n",max_i);
	}
}
