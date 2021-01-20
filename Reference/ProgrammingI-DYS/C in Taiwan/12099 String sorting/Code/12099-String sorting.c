#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define COL 101

char input[200000][COL];
int len;

int compare_Str (const void *a, const void *b)
{
    const char *ia = (const char *) a;
    const char *ib = (const char *) b;
    return strcmp(ia,ib);
}

int main(void)
{
    int i;

    while(scanf("%s",input[len])!=EOF)
    {
        len++;
    }

    qsort(input,len,sizeof(char) * COL,compare_Str);

    for(i=0;i<len;i++) printf("%s\n",input[i]);

    return 0;
}

