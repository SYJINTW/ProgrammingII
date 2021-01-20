#include <stdio.h>
int main()
{
   int i = 'A';
   do {
      if (i == 'C')
         continue;

      putchar(i);
   } while (++i < 'F');
   return 0;
}
