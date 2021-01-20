#include <stdio.h>
#include"10832.h"
int main(void)
{
    int n, i;
    int water;

    scanf("%d", &n);

    for (i = 0 ; i < n ; i++)
    {
        scanf("%d", &liters[i]);
    }

    scanf("%d", &water);
    filling(water, 0, n);
    return 0;
}

