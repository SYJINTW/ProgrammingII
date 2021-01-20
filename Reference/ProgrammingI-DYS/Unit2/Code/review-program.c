#include <stdio.h>

int square(double);

int main(void)
{
    int a;

    a = square(1.4);
    printf("The sqr. of %f is %d\n", 1.4, a);

    return 0;
}
int square(double x)
{
    return x*x;
}
