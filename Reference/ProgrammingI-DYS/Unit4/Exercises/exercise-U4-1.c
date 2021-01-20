#include <stdio.h>
void star(int);
/* function definition */

int main(void)
{
   int i = 5;
   float fl = 7.5;
   star(i);
   star((int) fl);
   return 0;
}


void star(int n)
{
   while (n > 0) {
      n--;
      printf("*");
   }
   printf("\n");
}

