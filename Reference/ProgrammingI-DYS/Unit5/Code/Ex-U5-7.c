#include <stdio.h>
#define CODE 13
int main(void)
{
   int code_entered;

   do {
      printf("Please enter the secret code number: ");
      scanf("%d", &code_entered);
   } while (code_entered != CODE);
   printf("Bingo!\n");

   return 0;
}
