#include<stdio.h>
int m,n,ans,lane[11],qr[11],qed,red;


int vld(int row){
	for(int i=0;i<row;i++){
		if(qr[i]||qr[row]){
			if(lane[i]==lane[row]||lane[i]-lane[row]==i-row||lane[i]-lane[row]==row-i)
			return 0;
		}
		else
			if(lane[i]==lane[row])	return 0;
	}
	return 1;
}

void rec(int row){
	if(row==m+n){
		ans++;
		return;
	}
	else{
		for(int i=0;i<m+n;i++){
			lane[row]=i;
			if(qed<m){
				qr[row]=1;
				qed++;
				if(vld(row))	rec(row+1);
				qed--;
				qr[row]=0;
				if(red<n&&vld(row)){
					red++;
					rec(row+1);
					red--;
				}
			}
			else{
				if(red<n&&vld(row)){ 
					red++;
					rec(row+1);
					red--;
				}
			}
		lane[row]=-1;
		}
	}
}

int main(){
	while(~scanf("%d %d",&m,&n)){
		ans=0;
		rec(0);
		printf("%d\n",ans);
		ans=0;
	}
}
