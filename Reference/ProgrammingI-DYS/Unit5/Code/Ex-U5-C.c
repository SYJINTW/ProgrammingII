/*

Find the smallest N that satisfies

    N % x == a

    N % y == b

    N % z == c

For example,

if x=3, y=5, z=7, and a=2, b=3, c=4,

then, N is 53 since

    53 % 3 == 2

    53 % 5 == 3

    53 % 7 == 4

and 53<=3*5*7.

Another test case:

Input:

23 29 37

10 20 30

Output:

14201

*/

#include <stdio.h>

int main(void)
{

    int x, y, z;
    int a, b, c;
    int i;
    int found=0; //0 means not-found

    scanf("%d%d%d", &x, &y, &z);
    scanf("%d%d%d", &a, &b, &c);

    for (i=1; i<=x*y*z; i++) {
        if(!found)
            if (i%x==a && i%y==b && i%z==c) {
                found=1; //An easier approach is: using break
                printf("%d\n", i);
            }
    }

    return 0;

}
