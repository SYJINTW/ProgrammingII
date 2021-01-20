#include<stdio.h>
int main(){
	int fd,bob,fds[200000],ans,temp;
	scanf("%d",&fd);
	for(int i=0;i<=fd;i++){
		scanf("%d",&fds[i]);
	}
	for(int i=0;i<=fd;i++){
		for(int j=0;j<fd-i;j++){
			if(fds[j]>fds[j+1]){
				temp=fds[j];
				fds[j]=fds[j+1];
				fds[j+1]=temp;
			}
		}
	}
	ans = (fds[fd] - fds[0]) * 2;
	printf("%d\n",ans);
} 
