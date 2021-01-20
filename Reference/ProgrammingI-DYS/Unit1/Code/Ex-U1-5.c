//An example that contains multiple functions
#include <stdio.h>

int print(void);
int square(int);

int main(void)
{
    print();
    return 0;
}
int print(void)
{
    printf("%d\n", square(5));
    return 0;
}
int square(int x)
{
    return x*x;
}
