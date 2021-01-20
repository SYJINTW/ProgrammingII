#include <stdio.h>

int main(void)
{
    int i, j;
    int a[10][10] = {1}; //The first element a[0][0] is initialized as 1 and all others as 0.

    for(i=1;i<=9;i++)
    {
        for(j=1;j<=9;j++)
        {
            a[i][j] = a[i-1][j-1]+a[i-1][j]; /* a[i][j] ith row, jth column */
        }

    }

    /* show the content of a */

    for(i=1;i<=9;i++)
    {
        for(j=1;j<=9;j++)
        {
            printf("%3d ", a[i][j]);
        }

        printf("\n");
    }

    return 0;
}
