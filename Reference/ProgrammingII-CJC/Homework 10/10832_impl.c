#include<stdio.h>
#include "10832.h"

void showResult(int n) {
    int i;
    printf("(%d", numbers[0]);
    for (i = 1; i < n ; i++)
    {
        printf(",%d", numbers[i]);
    }
    printf(")\n");
}
void filling(int amount, int cur, int n) {
    if (amount == 0) {
        showResult(n);
        return;
    }
    if(cur >= n)
        return;
    if (amount < 0)
        return;
    
    int i=amount;
    while (i >= 0) {
        // printf("amount = %d\n", amount);
        numbers[cur] = i;
        filling(amount - liters[cur]*i, cur+1, n);
        i--;
    }
}