#include <stdio.h>
#define CODE 7
int main(void)
{
   int num = 0;

   for (printf("Keep entering numbers!\n"); num != CODE; ) {       
      scanf("%d", &num);
   }
   printf("Bingo!\n");
   return 0;
}
