#include <stdio.h>

int main(void)
{
    int i, j;

    i = 1;

    while (i<=9) {

        printf("i=%d: ", i);
        j = 1;

        while (j<=9) {

            printf("%3d ", i*j);
            j++;

        }

        printf("\n");
        i++;

    }

    return 0;

}
