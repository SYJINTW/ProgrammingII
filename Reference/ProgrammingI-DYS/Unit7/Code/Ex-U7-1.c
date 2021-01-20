#include <stdio.h>
void f(int x);
int main(void)
{
   int x = 1;
   printf("main: %d\n", x);
   f(x);
   printf("main: %d\n", x);
   return 0;
}

void f(int x)
{
   x++;
   printf("f: %d\n", x);
}




