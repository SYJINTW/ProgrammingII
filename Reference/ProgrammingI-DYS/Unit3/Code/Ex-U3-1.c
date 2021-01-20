#include <stdio.h>
#include <string.h>
#define SPEED 0.083

int main(void)
{
   float minutes, distance;
   int size, letters;
   char name[10];

   printf("Hi! What's your first name? ");
   scanf("%9s", name);
   printf("\n%s, how many minutes does it take to walk from\n", name);
   printf("your dormitory to the CS building? ");
   scanf("%f", &minutes);
   size = sizeof(name);
   letters = strlen(name);

   distance = minutes * SPEED;  
   printf("\nThe distance from your dormitory to the CS building\n");
   printf("is about %.3f kilometers.\n\n", distance);
  
   printf("By the way, your first name has %d letters,\n", letters);
   printf("and we have %d bytes to store it in.\n", size);

   return 0;
}
