#include <stdio.h>
int main()
{
   int i = 'A';
   do {
      if (i == 'C')
         break;

      putchar(i);
   } while (++i < 'F');
   return 0;
}
