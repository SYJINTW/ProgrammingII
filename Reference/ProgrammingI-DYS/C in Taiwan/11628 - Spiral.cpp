#include<stdio.h>
int main(){
	int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
	int j,idcurrent=0,T,N,Ne,column,row;
	scanf("%d",&T);
	while(T--){
		char a[5000][5000]={0};
		scanf("%d",&N);
		Ne=N;
		idcurrent=0;
		row=0,column=-1;
		while(Ne){
			j=0;
			while(j<Ne){
				row=row+dir[idcurrent][0];
				column=column+dir[idcurrent][1];
				a[row][column]='#';
				j++;
			}
			Ne--;
			idcurrent=(idcurrent+1)%4;
		}
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				if(a[i][j]=='#'){
					printf("%c",a[i][j]);
					}
				else
					printf(" ");
			}
					printf("\n");
		}
	}
}
