#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
bool map[1010][1010];
bool can_teleport;
char a[1010][1010];
int N,M;
void dfs(int ,int);
int main(){
	int times;
	scanf("%d",&times);
	while(times--){
		scanf("%d%d",&N,&M);
		for(int i=0;i<N;i++){
			scanf("%s",a[i]);
		}
		memset(map,false,sizeof(map));
		can_teleport=false;
		dfs(0,0);
		if(can_teleport){
			for(int i=0;i<N;i++)
				for(int j=0;j<M;j++)
					if(a[i][j]=='T')
						dfs(i,j);
		}
		if(map[N-1][M-1]){
			printf("Yes\n");
		}
		else{
			printf("No\n");
		}
	}
} 
void dfs(int x,int y){
	if(map[x][y]){
		return;
	}
	if(a[x][y]=='T'){
		can_teleport=true;
	}
	map[x][y]=true;
		
	int dx[4]={1,-1,0,0};
	int dy[4]={0,0,1,-1};
			
	for(int i=0;i<4;i++){
		int newx=x+dx[i];
		int newy=y+dy[i];
		if(newx<0||newy<0||newx>=N||newy>=M)
			continue;
		if(a[newx][newy]=='#')
			continue;
		dfs(newx,newy);
	}
}

