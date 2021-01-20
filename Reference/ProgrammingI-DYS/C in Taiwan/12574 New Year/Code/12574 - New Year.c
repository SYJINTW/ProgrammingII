#include <stdio.h>

#define N 100005

int n;
int pa[N];

int parent_uncle_aunt()
{
    int grandparent = pa[pa[n]], cnt = 0;
    for(int i = 1; i <= n; i++)
        if(pa[i] == grandparent) cnt++;
    return cnt;
}

int ancestors()
{
    int cnt = 0;
    for(int p = pa[n]; p != -1; p = pa[p]) cnt++;
    return cnt;
}

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &pa[i]);
    int ans = 0;
    ans += parent_uncle_aunt();
    ans += ancestors();
    ans -= 1; // "parent" is counted twice
    printf("%d\n", ans);
}
