#include <stdio.h>

int main(void)
{
    int x[10] = {0}; //All elements are initialized as 0!
    double y[5] = {2.0, 4.0, 6.0, 8.0, 10.0};
    char z[3] = {'A', 'B'}; //z[2] is not initialized!

    x[0] = 3;

    printf("x[0]: %d\n",x[0]);
    printf("x[7]: %d\n",x[7]);
    printf("y[1]: %f\n",y[1]);
    printf("z[0]: %c\n",z[0]);
    printf("z[2]: %c\n",z[2]);

    return 0;
}
