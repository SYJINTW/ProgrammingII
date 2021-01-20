#include <stdio.h>

int main(void)
{
    int n;
    int i; //i is a counter for the while-loops
    int x, sum;

    int a[50];

    printf("How many numbers? (n<50) ");
    scanf("%d", &n);

    i = 0;

    while (i<n) {
        printf("Input a[%d]: ", i);
        scanf("%d", &x);
        printf("The number is %d\n", x);
        a[i] = x;

        i = i + 1;
    }

    i = 0;
    sum = 0;

    while (i<n) {
        printf("%d + ", a[i]);
        sum = sum + a[i];
        i++;
    }

    printf("\b\b= %d\n", sum);

    return 0;
}
