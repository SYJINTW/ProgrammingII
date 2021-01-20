#include <stdio.h>
int main(void)
{
    int width, precision;
    double rate = 123.45;
    printf("Enter a width and a precision: ");
    scanf("%d %d", &width, &precision);
    printf("rate: '%*.*f'\n", width, precision, rate);
    return 0 ;
}
