#include <stdio.h>
#include <ctype.h>
int main(void)
{
   char ch;

   while ((ch = getchar()) != '\n') {
      if (isupper(ch)) {                 /* line 8  */
         ch = tolower(ch);               /* line 9  */
      }
      else if (islower(ch)) {            /* line 10 */
         ch = toupper(ch);               /* line 11 */
      }
      //else;
      //or
      //else
      //{
      //}
      putchar(ch);
   }
   putchar(ch);

   return 0;
}
