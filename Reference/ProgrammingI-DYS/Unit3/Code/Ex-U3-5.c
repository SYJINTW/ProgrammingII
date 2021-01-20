#include <stdio.h>

int main(void)
{
    int i, j;
    int a[10][10] = {1}; //The first element a[0][0] is initialized as 1 and all others as 0.

    i = 1;

    while (i<=9)
    {
        j = 1;

        while (j<=9)
        {
            a[i][j] = a[i-1][j-1]+a[i-1][j]; /* a[i][j] ith row, jth column */
            j = j + 1;
        }

        i = i + 1;
    }

    /* show the content of a */

    i = 1;

    while (i<=9)
    {
        j = 1;

        while (j<=9)
        {
            printf("%3d ", a[i][j]);
            j = j + 1;
        }

        printf("\n");
        i = i + 1;
    }

    return 0;
}
