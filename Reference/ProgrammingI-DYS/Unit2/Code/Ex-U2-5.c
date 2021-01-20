#include <stdio.h>

int main(void)
{
    float x = 12345.0;
    double y = 2.34e12;

    printf("%f or %e\n", x, x);
    printf("%f or %e\n", y, y);
    return 0;
}
