#include <stdio.h>

int main(void)
{
   int a = 31;
   int b = 20;
   int c ;

   c = a % b;
   printf("a: %d; b: %d; c: %d\n", a, b, c);

   c=a++;
   printf("a: %d; b: %d; c: %d\n", a, b, c);

   c=--b;
   printf("a: %d; b: %d; c: %d\n", a, b, c);

   return 0;
}
