#include<stdio.h>
int heights[10000001], previous[10000001];
int main(){
    int n, target, confort_level, cnt = 0;
    scanf("%d %d", &n, &target);
    int ans[n+1];
    for(int i=1; i<=n; i++) {
        scanf("%d", &heights[i]);
        confort_level=0;
        for(int j=i-1; j>=1; j--) {
            if(heights[j] < heights[i]) {
				confort_level++;
            }else   break;
        }
        if(confort_level == target)  ans[cnt++] = i;
    }
	if(cnt>0) {	//print answer
        printf("%d", ans[0]);
        for(int i=1; i<cnt; i++)    printf(" %d", ans[i]);
	}else printf("ouo");
    printf("\n");
    return 0;
}
