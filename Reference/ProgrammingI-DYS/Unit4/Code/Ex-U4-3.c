#include <stdio.h>
int main(void)
{
   char ch;
   int i;
   float fl=0;

   ch = 'C';
   ch = ch + 1;
   i = fl + 2 * ch;
   fl = 2.0 * ch + i;
   printf("ch = %c, i = %d, fl = %2.2f\n", ch, i, fl);

   return 0;
}
