#include <stdio.h>
#define FIRST_PACK 7
#define NEXT_PACK 5
int main(void)
{
   int n, cost;
   printf(" packs   costs\n");
   
   for (n=1, cost=FIRST_PACK ; n<=10 ; n++, cost += NEXT_PACK) {
      printf("%5d     $%-5d\n", n, cost);      
   }
   return 0;
}
