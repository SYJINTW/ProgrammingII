#include <stdio.h>

double power(double n, int p);

int main(void)
{
    printf("%f\n",power(3,4));

    return 0;
}

double power(double n, int p)
{
    double ans;

    //basis step
    if(p==0) return 1;

    //recursive step
    ans = power(n,p/2);
    if(p%2==0) return ans*ans;
    else return n*ans*ans;
}
