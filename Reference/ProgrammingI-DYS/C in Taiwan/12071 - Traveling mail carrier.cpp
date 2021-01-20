#include<stdio.h>
#include<limits.h>
int dis[11][11];
int n;
int visited_c=0;
int visited[11];
int min_dis=INT_MAX;
int distance=0;
void dfs(int cur);
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&dis[i][j]);
		}
	}
	visited[0]=1;
	visited_c=1;
	dfs(0);
	printf("%d\n",min_dis);
} 
void dfs(int cur){
	if(visited_c==n){
		if(min_dis>distance+dis[cur][0]){
			min_dis=distance+dis[cur][0];
		}
	}
	for(int i=0;i<n;i++){
		if(!visited[i]){
			visited_c++;
			visited[i]=1;
			distance+=dis[i][cur];
			dfs(i);
			visited_c--;
			visited[i]=0;
			distance-=dis[i][cur];
		}
	}
}
