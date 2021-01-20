#include <stdio.h>

int main(void)
{
    int T;
    int i;
    char in[5][3];
    int cards[14];
    int flag2,flag3;

    scanf("%d",&T);

    while(T--)
    {
        scanf("%s%s%s%s%s",in[0],in[1],in[2],in[3],in[4]);

        for(i=1;i<=13;i++) cards[i]=0;
        flag2=flag3=0;

        for(i=0;i<5;i++)
        {
            if(in[i][0]=='A') cards[1]++;
            else if(in[i][0]=='1') cards[10]++;
            else if(in[i][0]=='J') cards[11]++;
            else if(in[i][0]=='Q') cards[12]++;
            else if(in[i][0]=='K') cards[13]++;
            else
                cards[in[i][0]-'0']++;
        }

        for(i=1;i<=13;i++)
        {
            if(cards[i]==2) flag2=1;
            else if(cards[i]==3) flag3=1;
        }

        if(flag2==1&&flag3==1) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}
