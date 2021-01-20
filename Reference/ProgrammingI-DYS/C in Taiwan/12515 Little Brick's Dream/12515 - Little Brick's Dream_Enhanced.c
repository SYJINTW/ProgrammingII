#include<stdio.h>
int heights[10000001], confort_level[10000001];
int main(){
    int n, i, j, target, cnt = 0;
    scanf("%d %d", &n, &target);
    int ans[n+1];
    for( i=1; i<=n; i++) {
        scanf("%d", &heights[i]);
        for( j=i-1; j>=1;) {
            if(heights[j] < heights[i])	j-= confort_level[j]+1;
            else   break;
        }
		confort_level[i] = i-j-1;
        if(confort_level[i] == target)  ans[cnt++] = i;
    }
	if(cnt>0) {	//print answer
        printf("%d", ans[0]);
        for(int i=1; i<cnt; i++)    printf(" %d", ans[i]);
	}else printf("ouo");
    printf("\n");
    return 0;
}
