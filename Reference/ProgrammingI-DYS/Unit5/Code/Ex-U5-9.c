#include <stdio.h>
#include <ctype.h>
int main(void)
{
   char ch;

   while ((ch = getchar()) != '\n') {
      if (isalpha(ch))     /* if a letter,     */
         putchar(ch+1);    /* change           */
      else                 /* otherwise,       */
         putchar(ch);      /* print as is      */
   }
   putchar(ch);            /* print the newline */

   return 0;
}
