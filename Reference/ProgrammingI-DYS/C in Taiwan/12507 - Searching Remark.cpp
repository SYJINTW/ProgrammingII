#include <string.h>
#include <stdio.h>
#include <ctype.h>
char input[5000];
int main (void)
{
    int ans=0;
    int same; // 1 means same
    int i,j;
    char keyword[25];
    char divisor[15]={' ','(',')','\n','-','(',')','[',']',',','.',':','/'};
    char *token;
    fgets(keyword,25,stdin);
    for(i=0;i<strlen(keyword);i++)
    {
        if(isupper(keyword[i]))  keyword[i]=tolower(keyword[i]);
    }

    while(fgets(input,5000,stdin))
    {
        token=strtok(input,divisor);
        while(token!=NULL)
        {
            same=1;
            for(i=0;i<strlen(token);i++)
            {
                if(isupper(token[i])) token[i]=tolower(token[i]);
            }

            for(i=0;i<strlen(token);i++)
            {
                if(token[i]!=keyword[i])
                {
                    same=0;
                }
            }
            if(same==1) ans++;
            
            token=strtok(NULL,divisor);
        }
    }
    printf("%d\n",ans);
    return(0);

}

