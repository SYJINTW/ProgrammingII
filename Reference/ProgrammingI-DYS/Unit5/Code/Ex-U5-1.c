#include <stdio.h>

int main(void)
{
    int x;

    while (scanf("%d", &x) != EOF) { /*Ctrl Z + Enter */
        printf("x=%d\n", x);
    }

    return 0;
}
